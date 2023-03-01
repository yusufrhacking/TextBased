#include "EntityManager.h"


Entity EntityManager::createEntity() {
    int entityId = numOfEntities;
    numOfEntities++;
    Entity entity(entityId);
    entitiesToBeAdded.push_back(entity);
    spdlog::info("Entity " + std::to_string(entityId) + " created");
    return entity;
}

int EntityManager::getNumOfEntities() const {
    return numOfEntities;
}

std::vector<Entity> EntityManager::getEntitiesToBeAdded() {
    return entitiesToBeAdded;
}

std::vector<Entity> EntityManager::getEntitiesToBeKilled() {
    return entitiesToBeKilled;
}
