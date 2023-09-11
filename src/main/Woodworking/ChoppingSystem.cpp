#include <spdlog/spdlog.h>
#include "ChoppingSystem.h"
#include "../HighLevel/ECSManager.h"
#include "ChopEvent.h"

extern std::unique_ptr<ECSManager> ecsManager;
extern std::unique_ptr<EventBus> eventBus;

ChoppingSystem::ChoppingSystem() {
    listenToEvents();
}

void ChoppingSystem::listenToEvents() {
    eventBus->listenToEvent<ChopEvent>(this, &ChoppingSystem::onChop);
}

void ChoppingSystem::onChop(ChopEvent &event) {
    spdlog::debug("Chop received");
}
