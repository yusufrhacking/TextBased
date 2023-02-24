#include <spdlog/spdlog.h>
#include "ECSManager.h"

int GenericComponent::nextId = 0;

void ECSManager::update(){
    for (Entity entity : entitiesToBeAdded){
        addEntityToSystems(entity);
        spdlog::info("Entity " + std::to_string(entity.getId()) + " fully added");
    }
    entitiesToBeAdded.clear();
}

Entity ECSManager::createEntity() {
    int entityId = numOfEntities;
    numOfEntities++;

    if(numOfEntities >= entityComponentSignatures.size()){
        entityComponentSignatures.resize(numOfEntities);
    }

    Entity entity(entityId);
    entitiesToBeAdded.push_back(entity);
    spdlog::info("Entity " + std::to_string(entityId) + " created");
    return entity;
}

void ECSManager::addEntityToSystems(Entity entity){
    int entityId = entity.getId();
    auto entityComponentSignature = entityComponentSignatures[entityId];

    for (auto& systemKeyValuePair: systems){
        std::shared_ptr<System> system = systemKeyValuePair.second;
        ComponentSignature systemComponentSignature = system->getComponentSignature();

        if (signaturesMatch(entityComponentSignature, systemComponentSignature)){
            system->addEntity(entity);
            spdlog::info("Added Entity " + std::to_string(entityId) + " to system ");//Need System ID?
        }
    }
}

bool ECSManager::signaturesMatch(const std::bitset<64> &entityComponentSignature,
                                 const ComponentSignature &systemComponentSignature) const {
    return (entityComponentSignature & systemComponentSignature) == systemComponentSignature; }



bool ECSManager::isComponentPoolsResizeNeeded(const int componentId) const { return componentId >= componentPools.size(); }

bool ECSManager::isComponentUnitialized(const int componentId) { return !componentPools[componentId]; }
