#include "PlayerPickUpSystem.h"
#include "../HighLevel/ECSManager.h"
#include "PickupComponent.h"
#include "PlayerPickUpEvent.h"
#include "../PositionsAndMovement/PositionComponent.h"
#include "../MainPlayer/MainPlayerAccessSystem.h"
#include "../PositionsAndMovement/DistanceCalculator.h"
#include "InventoryComponent.h"
#include "../PositionsAndMovement/LiveComponent.h"
#include "../Creation/StashPlayerItemEvent.h"
#include "../MainPlayer/TiedChildComponent.h"
#include "../Woodworking/AxeComponent.h"

extern std::unique_ptr<ECSManager> ecsManager;
extern std::unique_ptr<EventBus> eventBus;

PlayerPickUpSystem::PlayerPickUpSystem(){
    requireComponent<PickupComponent>();
    listenToEvents();
}
void PlayerPickUpSystem::listenToEvents(){
    eventBus->listenToEvent<PlayerPickUpEvent>(this, &PlayerPickUpSystem::onPickup);
    eventBus->listenToEvent<StashPlayerItemEvent>(this, &PlayerPickUpSystem::onStash);
}
void PlayerPickUpSystem::onPickup(PlayerPickUpEvent& event){
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

void PlayerPickUpSystem::onStash(StashPlayerItemEvent& event) {
    switch (event.item) {
        case Item::AXE: stashAxe(); break;
        default: break;
    }
}

void PlayerPickUpSystem::stashAxe() {
    auto mainPlayer = *getRelevantEntities().begin();
    auto& children = ecsManager->getComponentFromEntity<TiedChildComponent>(mainPlayer).entities;
    for (auto child: children){
        if (ecsManager->hasComponent<AxeComponent>(child)){
            pickupItemIntoPlayerInventory(mainPlayer, child);
            break;
        }
    }
    //Basically need to find a way to get the axe entity seperately so that I can remove the text component from it... Or we can stash it once we have it
//    auto axe = ecsManager->getComponentFromEntity<AxeComponent>(tiedChild);
//    ecsManager->removeComponentFromEntity<TextComponent>(axe); //Need to figure out how to get the text component of the axe from player

}

void PlayerPickUpSystem::pickupItemIntoPlayerInventory(Entity player, Entity pickedUpEntity) {
    auto& playerInventory = ecsManager->getComponentFromEntity<InventoryComponent>(player);
    playerInventory.items.push_back(pickedUpEntity);
    ecsManager->removeComponentFromEntity<LiveComponent>(pickedUpEntity);
    spdlog::debug("Picking up Entity {}", pickedUpEntity.getId());
}
