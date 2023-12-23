#include "AxeFlipSystem.h"

#include "AxeComponent.h"
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
    eventBus->listenToEvent<FlipEvent>(this, &AxeFlipSystem::onAxeFlip);
}

void AxeFlipSystem::onAxeFlip(FlipEvent& event) {
    if (event.flipped != "axe") {
        return;
    }
    Entity mainPlayer = ecsManager->getSystem<MainPlayerAccessSystem>().getMainPlayer();
    EntitySize mainPlayerSize = ecsManager->getComponentFromEntity<TextComponent>(mainPlayer).getSurfaceSize();
    auto const& tiedChildren = ecsManager->getComponentFromEntity<TiedChildComponent>(mainPlayer).entities;
    for (const Entity child : tiedChildren) {
        if(ecsManager->hasComponent<AxeComponent>(child)) {
            auto& axeComponent = ecsManager->getComponentFromEntity<AxeComponent>(child);
            AxeConfig config = axeComponent.config;
            if (config == AxeConfig::RIGHT) {
                ecsManager->getComponentFromEntity<PositionComponent>(child).shiftPosition(-1*((int)mainPlayerSize.width), 0);
                axeComponent.config = AxeConfig::LEFT;
            }
            else if (config == AxeConfig::LEFT) {
                ecsManager->getComponentFromEntity<PositionComponent>(child).shiftPosition((mainPlayerSize.width), 0);
                axeComponent.config = AxeConfig::RIGHT;
            }
        }
    }

}

