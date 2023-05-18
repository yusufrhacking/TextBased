#include "ECSManager.h"
#include "../../Systems/UpdateSystems/MovementSystem.h"
#include "../../Systems/EventCreationSystems/EventCreationSystem.h"
#include <bitset>

int GenericComponent::nextId = 0;

void ECSManager::update(double deltaTime){
    addNewEntities();
    removeDeadEntities();
    runUpdateSystems(deltaTime);
    runEventSystems();
}

void ECSManager::runUpdateSystems(double deltaTime) const {
    for (const auto& system : systemManager->getSystemsOfType<UpdateSystem>()){
        system->update(deltaTime);
    }
}

void ECSManager::runEventSystems() {
    for (const auto& system: systemManager->getSystemsOfType<EventSystem>()){
        system->update(eventBus);
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
        ComponentSignature clearSignature = std::bitset<NUM_OF_COMPONENTS>();
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
    entityManager->killEntity(entity);
}

