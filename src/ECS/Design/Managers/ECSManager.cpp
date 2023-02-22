#include <spdlog/spdlog.h>
#include "ECSManager.h"

void ECSManager::Update(){

}

Entity ECSManager::createEntity() {
    return entityManager->createEntity();
}

void ECSManager::addEntityToSystem(Entity entity){
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




