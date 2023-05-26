#include "SystemManager.h"


void SystemManager::addNewEntityToSystem(Entity entity, ComponentSignature entitySignature){
    for (auto& systemKeyValuePair: systems){
        auto const& system = systemKeyValuePair.second;
        auto const& systemComponentSignature = system->getComponentSignature();

        if (entitySignature.matches(systemComponentSignature)){
            system->addEntity(entity);
        }

    }
}

void SystemManager::updateEntityInSystems(Entity entity, ComponentSignature entitySignature){
    for (auto& systemKeyValuePair: systems){
        auto const& system = systemKeyValuePair.second;
        auto const& systemComponentSignature = system->getComponentSignature();

        if (entitySignature.matches(systemComponentSignature)){
            system->addEntity(entity);
        }
        else{
            system->removeEntity(entity);
        }

    }
}
