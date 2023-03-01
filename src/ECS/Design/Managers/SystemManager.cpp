#include "SystemManager.h"


void SystemManager::addEntityToSystems(Entity entity, ComponentSignature entitySignature){
    int entityId = entity.getId();

    auto entityComponentSignature = entitySignature[entityId];

    for (auto& systemKeyValuePair: systems){
        std::shared_ptr<System> system = systemKeyValuePair.second;
        ComponentSignature systemComponentSignature = system->getComponentSignature();

        if (signaturesMatch(entitySignature, systemComponentSignature)){
            system->addEntity(entity);
            spdlog::info("Added Entity " + std::to_string(entityId) + " to system ");//Need System ID?
        }
    }
}

bool SystemManager::signaturesMatch(const ComponentSignature &entityComponentSignature, const ComponentSignature &systemComponentSignature) {
    return (entityComponentSignature & systemComponentSignature) == systemComponentSignature;
}