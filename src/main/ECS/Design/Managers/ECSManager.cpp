#include <spdlog/spdlog.h>
#include "ECSManager.h"
#include "../../Systems/EventCreationSystems/EventProducerSystem.h"
#include "../../Components/MainPlayerComponent.h"
#include "../../Systems/SpecialSystems/UnprocessedMovements/UnprocessedKeyboardMovementSystem.h"
#include "../../Systems/SpecialSystems/CameraFollowSystem.h"

int GenericComponent::nextId = 0;

extern std::unique_ptr<EventBus> eventBus;

void ECSManager::update(double deltaTime){
    addNewEntities();
    removeDeadEntities();
    systemManager->getSystem<UnprocessedKeyboardMovementSystem>().processMovement();
    runTimedSystems(deltaTime);
    systemManager->getSystem<CameraFollowSystem>().update();
}

void ECSManager::addNewEntities() {
    for (const Entity& entity : entityManager->getEntitiesToBeAdded()){
        auto signature = entityManager->getSignature(entity);
        spdlog::debug("Entity {} added to ECS manager", entity.getId());
        systemManager->addNewEntityToSystem(entity, signature);
    }
    entityManager->clearEntitiesToBeAdded();
}


void ECSManager::removeDeadEntities() {
    for (const Entity& entity : entityManager->getEntitiesToBeKilled()){
        removeEntity(entity);
        spdlog::debug("Entity [] removed from ECS manager", entity.getId());
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


void ECSManager::render(std::shared_ptr<Renderer> renderer){
    for (const auto& system : systemManager->getSystemsOfType<RenderSystem>()){
        system->render(renderer);
    }
}

Entity ECSManager::createEntity() {
    return entityManager->createEntity();
}

void ECSManager::killEntity(Entity entity) {
    if (!hasComponent<MainPlayerComponent>(entity))
        entityManager->killEntity(entity);
}




