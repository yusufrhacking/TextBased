#include "System.h"
#include "Component.h"

void System::addEntity(Entity entity) {
    entities.push_back(entity);
}

void System::removeEntity(Entity entity) {
    for(int index=0; index < entities.size(); index++){
        if (entities[index] == entity){
            entities.erase(entities.begin() + index);
            break;
        }
    }
}

std::vector<Entity> System::getEntities() const {
    return entities;
}

ComponentSignature System::getComponentSignature() const {
    return componentSignature;
}
