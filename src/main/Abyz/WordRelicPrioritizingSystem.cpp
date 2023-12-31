#include "WordRelicPrioritizingSystem.h"

#include <ranges>

#include "PriorityTargetComponent.h"
#include "../Health/PendingDeathComponent.h"
#include "../Maze/HalfwayOpenWallColumnPrefab.h"
#include "../Middlemarch/WordRelicComponent.h"
#include "../PositionsAndMovement/LiveComponent.h"
#include "../PositionsAndMovement/PositionComponent.h"

extern std::unique_ptr<ECSManager> ecsManager;

WordRelicPrioritizingSystem::WordRelicPrioritizingSystem() {
    requireComponent<WordRelicComponent>();
    requireComponent<PositionComponent>();
    requireComponent<LiveComponent>();
    requireComponent<TextComponent>();

    lastUpdateTime = std::chrono::steady_clock::now();

}

void WordRelicPrioritizingSystem::update(double deltaTime) {
    for(auto entity : std::ranges::reverse_view(getRelevantEntities())) {
        auto& relic = ecsManager->getComponentFromEntity<WordRelicComponent>(entity);
        if (relic.isCaptured) {
            continue;
        }

        auto currentTime = std::chrono::steady_clock::now();
        std::chrono::milliseconds timeDiff = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - lastUpdateTime);
        if (timeDiff.count() > workDelayMilliseconds) {
            lastUpdateTime = currentTime;
            ecsManager->addComponentToEntity<PriorityTargetComponent>(entity);
            ecsManager->removeComponentFromEntity<WordRelicComponent>(entity);
            // ecsManager->killEntity(entity);
        }
    }
}
