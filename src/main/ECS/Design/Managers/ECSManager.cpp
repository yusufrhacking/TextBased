#include "ECSManager.h"
#include "../../Systems/MovementSystem.h"

int GenericComponent::nextId = 0;

void ECSManager::update(double deltaTime){
    addNewEntities();
    removeDeadEntities();
    updateSystems(deltaTime);
}

void ECSManager::updateSystems(double deltaTime) const {
    for (const auto& system : systemManager->getSystemsOfType<UpdateSystem>()){
        system->update(deltaTime);
    }
}

void ECSManager::render(std::shared_ptr<Renderer> renderer){
    for (const auto& system : systemManager->getSystemsOfType<RenderSystem>()){
        system->update(renderer);
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
        ComponentSignature entitySignature = entityManager->getSignature(entity);
        entitySignature.reset();
        systemManager->updateEntityInSystems(entity, entitySignature);
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

