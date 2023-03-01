#include <spdlog/spdlog.h>
#include "ECSManager.h"

int GenericComponent::nextId = 0;

void ECSManager::update(double deltaTime){
    for (const auto& systemKeyPair : systemManager->getSystems()){
        auto system = systemKeyPair.second;
        system->update(deltaTime);
    }

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
