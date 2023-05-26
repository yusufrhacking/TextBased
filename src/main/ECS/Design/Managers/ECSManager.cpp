#include "ECSManager.h"
#include "../../Systems/UpdateSystems/AutonomousMovementSystem.h"
#include "../../Systems/EventCreationSystems/EventProducerSystem.h"
#include "../../Systems/UpdateSystems/CollisionCheckSystem.h"
#include "../../Systems/EventHandlerSystems/CollisionHandleSystem.h"
#include "../../Components/MainPlayerComponent.h"
#include "../../Systems/UpdateSystems/UnprocessedMovements/UnprocessedKeyboardMovementSystem.h"
#include "../../Systems/UpdateSystems/CameraFollowSystem.h"

int GenericComponent::nextId = 0;

extern std::unique_ptr<EventBus> eventBus;

void ECSManager::update(double deltaTime){
    addNewEntities();
    removeDeadEntities();
    systemManager->getSystem<UnprocessedKeyboardMovementSystem>().processMovement();
    runTimedSystems(deltaTime);
    runUntimedSystems();
    systemManager->getSystem<CameraFollowSystem>().update();
}

void ECSManager::runTimedSystems(double deltaTime) const {
    for (const auto& system : systemManager->getSystemsOfType<UpdateSystem>()){
        system->update(deltaTime);
    }
}

void ECSManager::runUntimedSystems() {
    for (const auto& system: systemManager->getSystemsOfType<EventProducerSystem>()){
        system->update();
    }
}


void ECSManager::render(std::shared_ptr<Renderer> renderer){
    for (const auto& system : systemManager->getSystemsOfType<RenderSystem>()){
        system->render(renderer);
    }
}


void ECSManager::addNewEntities() {
    for (const Entity& entity : entityManager->getEntitiesToBeAdded()){
        auto signature = entityManager->getSignature(entity);
        systemManager->addNewEntityToSystem(entity, signature);
    }
    entityManager->clearEntitiesToBeAdded();
}


void ECSManager::removeDeadEntities() {
    for (const Entity& entity : entityManager->getEntitiesToBeKilled()){
        ComponentSignature clearSignature;
        entityManager->setSignature(entity, clearSignature);
        ComponentSignature postSig = entityManager->getSignature(entity);
        componentManager->clearEntity(entity);
        systemManager->updateEntityInSystems(entity, clearSignature);
        entityManager->freeEntityID(entity.getId());
    }
    entityManager->clearEntitiesToBeRemoved();
}

Entity ECSManager::createEntity() {
    return entityManager->createEntity();
}

void ECSManager::killEntity(Entity entity) {
    if (!hasComponent<MainPlayerComponent>(entity))
        entityManager->killEntity(entity);
}




