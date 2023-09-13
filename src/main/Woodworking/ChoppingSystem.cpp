#include <spdlog/spdlog.h>
#include <stdexcept>
#include "AxeComponent.h"
#include "ChoppingSystem.h"
#include "../HighLevel/ECSManager.h"
#include "ChopEvent.h"
#include "../PositionsAndMovement/PositionComponent.h"
#include "TreeComponent.h"
#include "../MainPlayer/TiedChildComponent.h"
#include "../Creation/CreateItemEvent.h"
#include "../PositionsAndMovement/DistanceCalculator.h"

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
    auto axeTextComponent = getAxeTextComponent(mainPlayer);

    for(auto tree: trees){
        auto treePosition = ecsManager->getComponentFromEntity<PositionComponent>(tree).getPosition();
        auto& treeTextComponent = ecsManager->getComponentFromEntity<TextComponent>(tree);
        if (DistanceCalculator::isInAllowedRange(axePosition, treePosition, axeTextComponent, treeTextComponent, 100)){
            treeTextComponent.text = chopTreeText(treeTextComponent.text);
            if (treeTextComponent.text.empty()){
                eventBus->emitEvent<CreateItemEvent>(
                        CreateItemEvent(Item::WOOD_PILE, findTreeMiddle(treePosition)));
                ecsManager->killEntity(tree);
            }
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
    throw std::runtime_error("No Axe Found");
}


TextComponent ChoppingSystem::getAxeTextComponent(Entity mainPlayer) {
    const auto& children = ecsManager->getComponentFromEntity<TiedChildComponent>(mainPlayer).entities;
    for (auto child: children){
        if(ecsManager->hasComponent<AxeComponent>(child)){
            return ecsManager->getComponentFromEntity<TextComponent>(child);
        }
    }
    throw std::runtime_error("No Axe Found");
}

bool ChoppingSystem::isWithinAllowedDistance(Position axePosition, Position point, float allowedDistance) {
    float distanceSquared = std::pow(point.xPos - axePosition.xPos, 2) + std::pow(point.yPos - axePosition.yPos, 2);
    return distanceSquared <= std::pow(allowedDistance, 2);
}

