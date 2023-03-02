#include "SystemManager.h"


void SystemManager::addNewEntityToSystem(Entity entity, ComponentSignature entitySignature){
    int entityId = entity.getId();

    for (auto& systemKeyValuePair: systems){
        auto const& system = systemKeyValuePair.second;
        auto const& systemComponentSignature = system->getComponentSignature();

        if (signaturesMatch(entitySignature, systemComponentSignature)){
            system->addEntity(entity);
            spdlog::info("Added Entity " + std::to_string(entityId) + " to system ");//Need System ID?
        }
    }
}

void SystemManager::updateEntityInSystems(Entity entity, ComponentSignature entitySignature){
    int entityId = entity.getId();

    for (auto& systemKeyValuePair: systems){
        auto const& system = systemKeyValuePair.second;
        auto const& systemComponentSignature = system->getComponentSignature();

        if (signaturesMatch(entitySignature, systemComponentSignature)){
            system->addEntity(entity);
            spdlog::info("Added Entity " + std::to_string(entityId) + " to system ");//Need System ID?
        }
        else{
            system->removeEntity(entity);
            spdlog::info("Removed Entity " + std::to_string(entityId) + " to system ");//Need System ID?
        }
    }
}

SystemsMap SystemManager::getUpdateSystems() const {
    std::type_info updateSystemType = typeid(U)

    for (const auto& systemKeyPair : systems){
        auto system = systemKeyPair.second;
        if (typeid(system)){

        }
    }
    return systems;
}
