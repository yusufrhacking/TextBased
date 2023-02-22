#include <spdlog/spdlog.h>
#include "EntityManager.h"

Entity EntityManager::createEntity() {
    int entityId = numOfEntities;
    numOfEntities++;
    Entity entity(entityId);
    entitiesToBeAdded.push_back(entity);
    spdlog::error(&"Entity created with id: " [entityId]);
    return entity;
}

int EntityManager::getNumOfEntities() const {
    return numOfEntities;
}

std::vector<Entity> EntityManager::getEntitiesToBeAdded() {
    return entitiesToBeAdded;
}

std::vector<Entity> EntityManager::getEntitiesToBeRemoved() {
    return entitiesToBeRemoved;
}