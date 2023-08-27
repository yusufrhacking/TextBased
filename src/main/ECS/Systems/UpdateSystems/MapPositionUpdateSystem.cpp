#include "MapPositionUpdateSystem.h"

MapPositionUpdateSystem::MapPositionUpdateSystem() {
    requireComponent<PositionComponent>();
    //TODO: Require generic movement component
}

void MapPositionUpdateSystem::update(double deltaTime) {
    for (Entity entity: getRelevantEntities()){

    }
}
