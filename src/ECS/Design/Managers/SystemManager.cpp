#include "SystemManager.h"


void SystemManager::addNewEntityToSystem(Entity entity, ComponentSignature entitySignature){
    int entityId = entity.getId();

    for (auto& systemKeyValuePair: systems){

        auto const& system = systemKeyValuePair.second;
        auto const& systemComponentSignature = system->getComponentSignature();

        if (signaturesMatch(entitySignature, systemComponentSignature)){
            system->addEntity(entity);
            spdlog::debug("Added Entity " + std::to_string(entityId) + " to system ");//Need System ID?
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
            spdlog::debug("Added Entity " + std::to_string(entityId) + " to system ");//Need System ID?
        }
        else{
            system->removeEntity(entity);
            spdlog::debug("Removed Entity " + std::to_string(entityId) + " to system ");//Need System ID?
        }

    }
}
