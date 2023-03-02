#include <spdlog/spdlog.h>
#include "ECSManager.h"

int GenericComponent::nextId = 0;

void ECSManager::render(std::shared_ptr<Renderer> renderer){

}

void ECSManager::update(double deltaTime){
    addNewEntities();
    updateSystems(deltaTime);
}

void ECSManager::updateSystems(double deltaTime) const {
    for (const auto& systemKeyPair : systemManager->getUpdateSystems()){
        auto system = systemKeyPair.second;
        system->update(deltaTime);
    }
}

void ECSManager::addNewEntities() {
    for (const Entity& entity : entityManager->getEntitiesToBeAdded()){
        auto signature = entityManager->getSignature(entity);
        systemManager->addNewEntityToSystem(entity, signature);
        spdlog::info("Entity " + std::to_string(entity.getId()) + " fully added");
    }
    entityManager->clearEntitiesToBeAdded();
}

Entity ECSManager::createEntity() {
    return entityManager->createEntity();
}
