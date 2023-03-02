#include "EntityManager.h"


Entity EntityManager::createEntity() {
    int entityId = numOfEntities;
    numOfEntities++;
    Entity entity(entityId);
    entitiesToBeAdded.push_back(entity);
    spdlog::debug("Entity " + std::to_string(entityId) + " created");
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

ComponentSignature EntityManager::getSignature(Entity entity) {
    return signatures[entity.getId()];
}

void EntityManager::setSignature(Entity entity, ComponentSignature signature) {
    signatures[entity.getId()] = signature;
}

void EntityManager::clearEntitiesToBeAdded() {
    entitiesToBeAdded.clear();
}

void EntityManager::clearEntitiesToBeKilled() {
    entitiesToBeKilled.clear();
}
