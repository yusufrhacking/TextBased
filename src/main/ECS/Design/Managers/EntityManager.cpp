#include "EntityManager.h"

Entity EntityManager::createEntity() {
    int entityId;
    if (freedEntityIDs.empty()){
        entityId = numOfEntities;
        numOfEntities++;
    } else{
        entityId = freedEntityIDs.top();
        freedEntityIDs.pop();
    }
    Entity entity(entityId);
    entitiesToBeAdded.push_back(entity);
    return entity;
}

int EntityManager::getNumOfEntities() const {
    return numOfEntities;
}

std::vector<Entity> EntityManager::getEntitiesToBeAdded() {
    return entitiesToBeAdded;
}

std::vector<Entity> EntityManager::getEntitiesToBeKilled() {
    return entitiesToBeRemoved;
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

void EntityManager::clearEntitiesToBeRemoved() {
    entitiesToBeRemoved.clear();
}

void EntityManager::killEntity(Entity entity) {
    entitiesToBeRemoved.push_back(entity);
}

void EntityManager::freeEntityID(int id) {
    freedEntityIDs.push(id);
}
