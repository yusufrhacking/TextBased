#include "MapGenerationSystem.h"

MapGenerationSystem::MapGenerationSystem() {
    requireComponent<PositionComponent>();
    //TODO: Require generic movement component
}

void MapGenerationSystem::update(double deltaTime) {
    for (Entity entity: getRelevantEntities()){

    }
}
