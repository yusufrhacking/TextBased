#include <spdlog/spdlog.h>
#include <stdexcept>
#include "AxeComponent.h"
#include "ChoppableComponent.h"
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
#include "../Health/PendingDeathComponent.h"
#include "../Attacking/ActiveWeaponComponent.h"

extern std::unique_ptr<ECSManager> ecsManager;
extern std::unique_ptr<EventBus> eventBus;

ChoppingSystem::ChoppingSystem() {
    requireComponent<TextComponent>();
    requireComponent<PositionComponent>();
    requireComponent<LiveComponent>();
    requireComponent<TreeComponent>();
    requireComponent<ChoppableComponent>();
    listenToEvents();
}

void ChoppingSystem::listenToEvents() {
    eventBus->listenToEvent<ChopEvent>(this, &ChoppingSystem::onChop);
    eventBus->listenToEvent<PunchEvent>(this, &ChoppingSystem::onPunch);
}

void ChoppingSystem::onChop(ChopEvent &event) {
    auto mainPlayer = ecsManager->getSystem<MainPlayerAccessSystem>().getMainPlayer();

    if (hasAxe(mainPlayer)){
        chopWithAxe(getAxeEntity(mainPlayer));
    }
}

void ChoppingSystem::onPunch(PunchEvent &event) {
    auto mainPlayer = ecsManager->getSystem<MainPlayerAccessSystem>().getMainPlayer();
    chopWithPunch(mainPlayer);
}


void ChoppingSystem::chopWithAxe(Entity axeEntity) {
    auto axePosition = ecsManager->getComponentFromEntity<PositionComponent>(axeEntity).getPosition();
    auto axeTextComponent = ecsManager->getComponentFromEntity<TextComponent>(axeEntity);
    auto axeComponent = ecsManager->getComponentFromEntity<AxeComponent>(axeEntity);

    for(auto tree: getRelevantEntities()){
        auto treePosition = ecsManager->getComponentFromEntity<PositionComponent>(tree).getPosition();
        auto& treeTextComponent = ecsManager->getComponentFromEntity<TextComponent>(tree);
        if (DistanceCalculator::isInAllowedRange(
                axePosition, treePosition, axeTextComponent.getSurfaceSize(),
                treeTextComponent.getSurfaceSize(), CHOPPING_RANGE)){
            tryToChopTree(tree, axeComponent.axeDamageToTree);
            spdlog::debug("CHOPPED");
            break;
        }
    }
}

void ChoppingSystem::chopWithPunch(Entity mainPlayer) {
    auto mainPlayerPosition = ecsManager->getComponentFromEntity<PositionComponent>(mainPlayer).getPosition();
    auto mainPlayerTextComponent = ecsManager->getComponentFromEntity<TextComponent>(mainPlayer);

    for(auto tree: getRelevantEntities()){
        auto treePosition = ecsManager->getComponentFromEntity<PositionComponent>(tree).getPosition();
        auto& treeTextComponent = ecsManager->getComponentFromEntity<TextComponent>(tree);
        if (DistanceCalculator::isInAllowedRange(
                mainPlayerPosition, treePosition, mainPlayerTextComponent.getSurfaceSize(),
                treeTextComponent.getSurfaceSize(), CHOPPING_RANGE)){
            tryToChopTree(tree, PUNCH_TREE_DAMAGE);
            spdlog::debug("CHOPPED");
            break;
        }
    }
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

bool ChoppingSystem::hasAxe(Entity mainPlayer) {
    if (ecsManager->hasComponent<ActiveWeaponComponent>(mainPlayer)){
        auto weaponEntity = ecsManager->getComponentFromEntity<ActiveWeaponComponent>(mainPlayer).entity;
        return (ecsManager->hasComponent<AxeComponent>(weaponEntity));
    }
    return false;
}

Entity ChoppingSystem::getAxeEntity(Entity mainPlayer) {
    if (ecsManager->hasComponent<ActiveWeaponComponent>(mainPlayer)){
        return ecsManager->getComponentFromEntity<ActiveWeaponComponent>(mainPlayer).entity;
    }
    throw std::runtime_error("NO AXE");
}

void ChoppingSystem::tryToChopTree(Entity tree, int damage) {
    auto& treeTextComponent = ecsManager->getComponentFromEntity<TextComponent>(tree);
    auto& treeChopComponent = ecsManager->getComponentFromEntity<ChoppableComponent>(tree);

    treeChopComponent.intermediateDamage += damage;
    if (treeChopComponent.isReadyToBreak()){
        treeTextComponent.text = chopTreeText(treeTextComponent.text);
        treeChopComponent.chop();
    }
    if (treeTextComponent.text.empty()){
        ecsManager->addComponentToEntity<PendingDeathComponent>(tree);
    }
}


