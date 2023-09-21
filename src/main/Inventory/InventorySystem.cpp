#include "InventorySystem.h"
#include "../HighLevel/ECSManager.h"
#include "InventoryPickupComponent.h"
#include "PlayerPickUpEvent.h"
#include "../PositionsAndMovement/PositionComponent.h"
#include "../MainPlayer/MainPlayerAccessSystem.h"
#include "../PositionsAndMovement/DistanceCalculator.h"
#include "InventoryComponent.h"
#include "../PositionsAndMovement/LiveComponent.h"
#include "StashPlayerItemEvent.h"
#include "../MainPlayer/TiedChildComponent.h"
#include "../Woodworking/AxeComponent.h"

extern std::unique_ptr<ECSManager> ecsManager;
extern std::unique_ptr<EventBus> eventBus;

InventorySystem::InventorySystem(){
    requireComponent<InventoryPickupComponent>();
    listenToEvents();
}
void InventorySystem::listenToEvents(){
    eventBus->listenToEvent<PlayerPickUpEvent>(this, &InventorySystem::onPickup);
    eventBus->listenToEvent<StashPlayerItemEvent>(this, &InventorySystem::onStash);
}
void InventorySystem::onPickup(PlayerPickUpEvent& event){
    auto player = event.picker;
    auto playerPosition = ecsManager->getComponentFromEntity<PositionComponent>(player).getPosition();
    auto playerSize = ecsManager->getComponentFromEntity<TextComponent>(player).getSurfaceSize();

    for(auto pickupEntity: getRelevantEntities()){
        auto pickupPosition = ecsManager->getComponentFromEntity<PositionComponent>(pickupEntity).getPosition();
        auto pickupSize = ecsManager->getComponentFromEntity<TextComponent>(pickupEntity).getSurfaceSize();

        if (DistanceCalculator::isInAllowedRange(playerPosition, pickupPosition, playerSize, pickupSize, PICKUP_RANGE)){
            pickupItemIntoPlayerInventory(player, pickupEntity);
        }
    }
}

void InventorySystem::onStash(StashPlayerItemEvent& event) {
    switch (event.item) {
        case Item::AXE: stashAxe(); break;
        default: break;
    }
}

void InventorySystem::stashAxe() {
    auto mainPlayer = ecsManager->getSystem<MainPlayerAccessSystem>().getMainPlayer();
    auto& children = ecsManager->getComponentFromEntity<TiedChildComponent>(mainPlayer).entities;

    for (auto it = children.begin(); it != children.end(); ) {
        if (ecsManager->hasComponent<AxeComponent>(*it)) {
            pickupItemIntoPlayerInventory(mainPlayer, *it);
            children.erase(it);
            break;
        } else {
            ++it;
        }
    }
}

void InventorySystem::pickupItemIntoPlayerInventory(Entity player, Entity pickedUpEntity) { //This is probably where things need to be changed because of the vector change
    auto& playerInventory = ecsManager->getComponentFromEntity<InventoryComponent>(player);
    playerInventory.items.push_back(pickedUpEntity);
    ecsManager->removeComponentFromEntity<LiveComponent>(pickedUpEntity);
    spdlog::debug("Picking up Entity {}", pickedUpEntity.getId());
}
