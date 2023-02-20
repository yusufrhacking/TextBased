#include <spdlog/spdlog.h>
#include "ECSManager.h"

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

void ECSManager::addEntityToSystem(Entity entity){

}

