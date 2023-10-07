#include <spdlog/spdlog.h>
#include "ECSManager.h"
#include "../Rendering/RenderControllerSystem.h"


int GenericComponent::nextId = 0;

extern std::unique_ptr<EventBus> eventBus;

ECSManager::ECSManager(Position startingPosition) {
    entityManager = std::make_shared<EntityManager>();
    componentManager = std::make_shared<ComponentManager>();
    systemManager = std::make_shared<SystemManager>();
    currentCamera.positionCamera(startingPosition);
}

std::vector<Entity> ECSManager::addNewEntities() {
    for (const Entity& entity : entityManager->getEntitiesToBeAdded()){
        auto signature = entityManager->getSignature(entity);
        spdlog::debug("Entity {} added to ECS manager", entity.getId());
        systemManager->addNewEntityToSystem(entity, signature);
    }
    auto recentlyAdded = entityManager->getEntitiesToBeAdded();
    entityManager->clearEntitiesToBeAdded();
    return recentlyAdded;
}


void ECSManager::removeDeadEntities() {
    for (const Entity& entity : entityManager->getEntitiesToBeKilled()){
        removeEntity(entity);
        spdlog::debug("Entity {} removed from ECS manager", entity.getId());
    }
    entityManager->clearEntitiesToBeRemoved();
}

void ECSManager::removeEntity(const Entity &entity) {
    ComponentSignature clearSignature;
    entityManager->setSignature(entity, clearSignature);
    ComponentSignature postSig = entityManager->getSignature(entity);
    componentManager->clearEntity(entity);
    systemManager->updateEntityInSystems(entity, clearSignature);
    entityManager->freeEntityID(entity.getId());
}

void ECSManager::runTimedSystems(double deltaTime) const {
    for (const auto& system : systemManager->getSystemsOfType<UpdateSystem>()){
        system->update(deltaTime);
    }
}


void ECSManager::render(const std::shared_ptr<Renderer>& renderer){
    renderer->renderClear();
    for (const auto& system : systemManager->getSystemsOfType<RenderControllerSystem>()){
        system->render(renderer, currentCamera);
    }
    renderer->renderPresent();
}

Entity ECSManager::createEntity() {
    return entityManager->createEntity();
}

void ECSManager::killEntity(Entity entity) {
    if (!hasComponent<MainPlayerComponent>(entity)){
        entityManager->killEntity(entity);
    } else{
        spdlog::debug("Main Player Should Have Died!");
    }
}

void ECSManager::runFirstSystems() const {
    for (const auto& system : systemManager->getSystemsOfType<FirstSystem>()){
        system->run();
    }
}

void ECSManager::runCameraSystem() {
    for (const auto& system : systemManager->getSystemsOfType<CameraFollowSystem>()){
        currentCamera = system->updateCameraPosition(currentCamera.getCameraPosition());
    }
}




