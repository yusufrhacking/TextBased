#include <spdlog/spdlog.h>
#include <stdexcept>
#include "AxeComponent.h"
#include "ChoppingSystem.h"
#include "../HighLevel/ECSManager.h"
#include "ChopEvent.h"
#include "../PositionsAndMovement/PositionComponent.h"
#include "TreeComponent.h"
#include "../MainPlayer/TiedChildComponent.h"

extern std::unique_ptr<ECSManager> ecsManager;
extern std::unique_ptr<EventBus> eventBus;

ChoppingSystem::ChoppingSystem() {
    requireComponent<TextComponent>();
    requireComponent<PositionComponent>();
    listenToEvents();
}

void ChoppingSystem::listenToEvents() {
    eventBus->listenToEvent<ChopEvent>(this, &ChoppingSystem::onChop);
}

void ChoppingSystem::onChop(ChopEvent &event) {
    auto trees = std::vector<Entity>{};
    Entity mainPlayer{-1};
    for(auto entity: getRelevantEntities()){
        if (ecsManager->hasComponent<TreeComponent>(entity)){
            trees.push_back(entity);
        }
        if (ecsManager->hasComponent<MainPlayerComponent>(entity)){
            mainPlayer = entity;
        }
    }
    if (mainPlayer.getId() == -1){
        throw std::runtime_error("No main player");
    }

    auto axePosition = getAxePosition(mainPlayer);

    for(auto tree: trees){
        auto treePosition = ecsManager->getComponentFromEntity<PositionComponent>(tree).getPosition();
        if (isInChoppingRange(axePosition, treePosition, 50)){
            spdlog::debug("CHOPPED");
        }
    }



    spdlog::debug("Chop received");
}

Position ChoppingSystem::getAxePosition(Entity mainPlayer) {
    const auto& children = ecsManager->getComponentFromEntity<TiedChildComponent>(mainPlayer).entities;
    for (auto child: children){
        if(ecsManager->hasComponent<AxeComponent>(child)){
            return ecsManager->getComponentFromEntity<PositionComponent>(child).getPosition();
        }
    }
    return {-1, -1};
}

bool ChoppingSystem::isInChoppingRange(Position axePosition, Position treePosition, float allowedDistance) {
    float distanceSquared = std::pow(treePosition.xPos - axePosition.xPos, 2) +
                            std::pow(treePosition.yPos - axePosition.yPos, 2);

    return distanceSquared <= std::pow(allowedDistance, 2);
}
