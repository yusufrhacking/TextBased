#include "ECSManager.h"

int GenericComponent::nextId = 0;

void ECSManager::update(double deltaTime){
    addNewEntities();
    updateSystems(deltaTime);
}

void ECSManager::updateSystems(double deltaTime) const {
    for (const auto& systemKeyPair : systemManager->getSystemsOfType<UpdateSystem>()){
        std::shared_ptr<UpdateSystem> system = systemKeyPair.second;
        system->update(deltaTime);
    }
}

void ECSManager::render(std::shared_ptr<Renderer> renderer){
    for (const auto& systemKeyPair : systemManager->getSystemsOfType<RenderSystem>()){
        std::shared_ptr<RenderSystem> system = systemKeyPair.second;
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

Entity ECSManager::createEntity() {
    return entityManager->createEntity();
}
