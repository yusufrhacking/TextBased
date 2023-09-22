#include <spdlog/spdlog.h>
#include <stdexcept>
#include "AxeComponent.h"
#include "ChoppingSystem.h"
#include "../HighLevel/ECSManager.h"
#include "ChopEvent.h"
#include "../PositionsAndMovement/PositionComponent.h"
#include "TreeComponent.h"
#include "../MainPlayer/TiedChildComponent.h"
#include "../Creation/CreateItemAtPositionEvent.h"
#include "../PositionsAndMovement/DistanceCalculator.h"
#include "../PositionsAndMovement/LiveComponent.h"
#include "../MainPlayer/MainPlayerAccessSystem.h"

extern std::unique_ptr<ECSManager> ecsManager;
extern std::unique_ptr<EventBus> eventBus;

ChoppingSystem::ChoppingSystem() {
    requireComponent<TextComponent>();
    requireComponent<PositionComponent>();
    requireComponent<LiveComponent>();
    requireComponent<TreeComponent>();
    listenToEvents();
}

void ChoppingSystem::listenToEvents() {
    eventBus->listenToEvent<ChopEvent>(this, &ChoppingSystem::onChop);
}

void ChoppingSystem::onChop(ChopEvent &event) {
    auto mainPlayer = ecsManager->getSystem<MainPlayerAccessSystem>().getMainPlayer();

    Position axePosition;
    TextComponent axeTextComponent;

    try{
        axePosition = getAxePosition(mainPlayer);
        axeTextComponent = getAxeTextComponent(mainPlayer);
    } catch (...){
        return;
    }


    for(auto tree: getRelevantEntities()){
        auto treePosition = ecsManager->getComponentFromEntity<PositionComponent>(tree).getPosition();
        auto& treeTextComponent = ecsManager->getComponentFromEntity<TextComponent>(tree);
        if (DistanceCalculator::isInAllowedRange(
                axePosition, treePosition, axeTextComponent.getSurfaceSize(),
                treeTextComponent.getSurfaceSize(), CHOPPING_RANGE)){
            treeTextComponent.text = chopTreeText(treeTextComponent.text);
            if (treeTextComponent.text.empty()){
                eventBus->emitEvent<CreateItemAtPositionEvent>(
                        CreateItemAtPositionEvent(Item::WOOD, findTreeMiddle(treePosition)));
                ecsManager->killEntity(tree);
            }
            spdlog::debug("CHOPPED");
            break;
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

Position ChoppingSystem::findTreeMiddle(Position treePosition) {
    auto surface = TextComponent::getSurfaceSize(TextGenerator::getTreeText());
    auto xSize = surface.width/2;
    auto ySize = surface.height/2;
    spdlog::debug("Big difference {}, {}", xSize, ySize);
    return treePosition + Position((float)xSize, (float)ySize);
}

std::string ChoppingSystem::chopTreeText(const std::string& treeText) {
    auto lastNewlinePos = treeText.find_last_of('\n');
    if (lastNewlinePos == std::string::npos) {
        return "";
    }
    return treeText.substr(0, lastNewlinePos);
}

