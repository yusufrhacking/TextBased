#include "System.h"

void System::addEntity(Entity entity) {
    entities.insert(entity);
}

void System::removeEntity(Entity entity) {
    entities.erase(entity);
}

std::set<Entity> System::getReleventEntities() const {
    return entities;
}

ComponentSignature System::getComponentSignature() const {
    return componentSignature;
}
