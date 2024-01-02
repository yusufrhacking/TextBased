#include "WordRelicPrioritizingSystem.h"

#include <ranges>

#include "PriorityTargetComponent.h"
#include "../Health/PendingDeathComponent.h"
#include "../Maze/HalfwayOpenWallColumnPrefab.h"
#include "../Middlemarch/WordRelicComponent.h"
#include "../PositionsAndMovement/LiveComponent.h"
#include "../PositionsAndMovement/PositionComponent.h"

extern std::unique_ptr<ECSManager> ecsManager;
extern std::unique_ptr<EventBus> eventBus;

WordRelicPrioritizingSystem::WordRelicPrioritizingSystem() {
    requireComponent<WordRelicComponent>();
    requireComponent<PositionComponent>();
    requireComponent<LiveComponent>();
    requireComponent<TextComponent>();
    start = false;

    lastUpdateTime = std::chrono::steady_clock::now();
    eventBus->listenToEvent<EndOfReadingEvent>(this, &WordRelicPrioritizingSystem::onEndOfReading);
}

void WordRelicPrioritizingSystem::onEndOfReading(EndOfReadingEvent& event) {
    start = true;
}

void WordRelicPrioritizingSystem::update(double deltaTime) {
    if (!start) {
        return;
    }
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
