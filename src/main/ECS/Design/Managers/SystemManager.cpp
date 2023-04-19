#include "SystemManager.h"


void SystemManager::addNewEntityToSystem(Entity entity, ComponentSignature entitySignature){
    int entityId = entity.getId();

    for (auto& systemKeyValuePair: systems){

        auto const& system = systemKeyValuePair.second;
        auto const& systemComponentSignature = system->getComponentSignature();

        if (signaturesMatch(entitySignature, systemComponentSignature)){
            system->addEntity(entity);
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
        }
        else{
            system->removeEntity(entity);
        }

    }
}
