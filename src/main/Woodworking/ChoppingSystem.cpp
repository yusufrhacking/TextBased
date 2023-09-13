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
        auto& treeTextComponent = ecsManager->getComponentFromEntity<TextComponent>(tree);
        if (isInChoppingRange(axePosition, treePosition, treeTextComponent, 100)){
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
    return {-1, -1};
}

bool ChoppingSystem::isInChoppingRange(Position axePosition, Position treePosition, const TextComponent& treeTextComponent, float allowedDistance) {
    if (isWithinTreeBounds(axePosition, treePosition, treeTextComponent)) {
        return true;
    }
    Position closestPartOfTree = getClosestPartOfTree(axePosition, treePosition, treeTextComponent);
    return isWithinAllowedDistance(axePosition, closestPartOfTree, allowedDistance);
}

bool ChoppingSystem::isWithinTreeBounds(Position axePosition, Position treePosition, const TextComponent& treeTextComponent) {
    auto treeSize = treeTextComponent.getSurfaceSize();

    bool isWithinHorizontalBounds = axePosition.xPos >= treePosition.xPos && axePosition.xPos <= treePosition.xPos + treeSize.width;
    bool isWithinVerticalBounds = axePosition.yPos >= treePosition.yPos && axePosition.yPos <= treePosition.yPos + treeSize.height;

    return isWithinHorizontalBounds && isWithinVerticalBounds;
}

Position ChoppingSystem::getClosestPartOfTree(Position axePosition, Position treePosition, const TextComponent& treeTextComponent) {
    auto treeSize = treeTextComponent.getSurfaceSize();

    float closestX = std::clamp(axePosition.xPos, treePosition.xPos, treePosition.xPos + treeSize.width);
    float closestY = std::clamp(axePosition.yPos, treePosition.yPos, treePosition.yPos + treeSize.height);

    return {closestX, closestY};
}

bool ChoppingSystem::isWithinAllowedDistance(Position axePosition, Position point, float allowedDistance) {
    float distanceSquared = std::pow(point.xPos - axePosition.xPos, 2) + std::pow(point.yPos - axePosition.yPos, 2);
    return distanceSquared <= std::pow(allowedDistance, 2);
}


std::string ChoppingSystem::chopTreeText(const std::string& treeText) {
    auto lastNewlinePos = treeText.find_last_of('\n');
    if (lastNewlinePos == std::string::npos) {
        return "";
    }
    return treeText.substr(0, lastNewlinePos);
}

Position ChoppingSystem::findTreeMiddle(Position treePosition) {
    auto surface = TextComponent::getSurfaceSize(TextGenerator::getTreeText());
    auto xSize = surface.width/2;
    auto ySize = surface.height/2;
    spdlog::debug("Big difference {}, {}", xSize, ySize);
    return treePosition + Position((float)xSize, (float)ySize);
}

