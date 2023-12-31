#include "AbyzPrioritizingSystem.h"

#include "../Health/PendingDeathComponent.h"
#include "../Maze/HalfwayOpenWallColumnPrefab.h"
#include "../Middlemarch/WordRelicComponent.h"
#include "../PositionsAndMovement/LiveComponent.h"
#include "../PositionsAndMovement/PositionComponent.h"

AbyzPrioritizingSystem::AbyzPrioritizingSystem() {
    requireComponent<WordRelicComponent>();
    requireComponent<PositionComponent>();
    requireComponent<LiveComponent>();
    requireComponent<TextComponent>();

    lastUpdateTime = std::chrono::steady_clock::now();

}

void AbyzPrioritizingSystem::update(double deltaTime) {
    for(auto entity: getRelevantEntities()) {
        auto& relic = ecsManager->getComponentFromEntity<WordRelicComponent>(entity);
        if (relic.isCaptured) {
            continue;
        }

        auto currentTime = std::chrono::steady_clock::now();
        std::chrono::milliseconds timeDiff = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - lastUpdateTime);
        if (timeDiff.count() > workDelayMilliseconds) {
            lastUpdateTime = currentTime;
            ecsManager->killEntity(entity);
        }
    }
}
