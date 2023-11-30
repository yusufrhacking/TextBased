#include "AxeFlipSystem.h"
#include "../EventSystem/EventBus.h"
#include "../MainPlayer/MainPlayerAccessSystem.h"
#include "../MainPlayer/TiedChildComponent.h"
#include "../Maze/HalfwayOpenWallColumnPrefab.h"

extern std::unique_ptr<EventBus> eventBus;
extern std::unique_ptr<ECSManager> ecsManager;


AxeFlipSystem::AxeFlipSystem() {
    listenToEvents();
}

void AxeFlipSystem::listenToEvents() {
    eventBus->listenToEvent<AxeFlipEvent>(this, &AxeFlipSystem::onAxeFlip);
}

void AxeFlipSystem::onAxeFlip(AxeFlipEvent& event) {
    Entity mainPlayer = ecsManager->getSystem<MainPlayerAccessSystem>().getMainPlayer();
    auto tiedChildren = ecsManager->getComponentFromEntity<TiedChildComponent>(mainPlayer).entities;

}

