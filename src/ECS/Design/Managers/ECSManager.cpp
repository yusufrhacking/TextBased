#include <spdlog/spdlog.h>
#include "ECSManager.h"

int GenericComponent::nextId = 0;

void ECSManager::Update(){

}

Entity ECSManager::createEntity() {
    int entityId = numOfEntities;
    numOfEntities++;
    Entity entity(entityId);
    entitiesToBeAdded.push_back(entity);
    spdlog::error(&"Entity created with id: " [entityId]);
    return entity;
}

void ECSManager::addEntityToSystems(Entity entity){
    int entityId = entity.getId();
    auto entityComponentSignature = entityComponentSignatures[entityId];

    for (auto& systemKeyValuePair: systems){
        System* system = systemKeyValuePair.second;
        ComponentSignature systemComponentSignature = system->getComponentSignature();

        if (signaturesMatch(entityComponentSignature, systemComponentSignature)){
            system->addEntity(entity);
        }
    }
}

bool ECSManager::signaturesMatch(const std::bitset<64> &entityComponentSignature,
                                 const ComponentSignature &systemComponentSignature) const {
    return (entityComponentSignature & systemComponentSignature) == systemComponentSignature; }



bool ECSManager::isComponentPoolsResizeNeeded(const int componentId) const { return componentId >= componentPools.size(); }

bool ECSManager::isComponentUnitialized(const int componentId) { return !componentPools[componentId]; }
