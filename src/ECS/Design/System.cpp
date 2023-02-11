#include "System.h"
#include "Component.h"

void System::addEntity(Entity entity) {

}

void System::removeEntity(Entity entity) {

}

std::vector<Entity> System::getEntities(Entity entity) const {
    return entities;
}

ComponentSignature System::getComponentSignature() const {
    return componentSignature;
}
