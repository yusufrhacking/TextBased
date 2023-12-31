#include "AbyzPrioritizingSystem.h"

#include "../Maze/HalfwayOpenWallColumnPrefab.h"
#include "../Middlemarch/WordRelicComponent.h"
#include "../PositionsAndMovement/LiveComponent.h"
#include "../PositionsAndMovement/PositionComponent.h"

AbyzPrioritizingSystem::AbyzPrioritizingSystem() {
    requireComponent<WordRelicComponent>();
    requireComponent<PositionComponent>();
    requireComponent<LiveComponent>();
    requireComponent<TextComponent>();
}

void AbyzPrioritizingSystem::update(double deltaTime) {
    for(auto entity: getRelevantEntities()) {
        auto& relic = ecsManager->getComponentFromEntity<WordRelicComponent>(entity);
        if (relic.isCaptured) {
            continue;
        }
    }
}
