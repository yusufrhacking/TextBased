#include "PlayerPickUpSystem.h"
#include "../HighLevel/ECSManager.h"
#include "PickupComponent.h"
#include "PlayerPickUpEvent.h"
#include "../PositionsAndMovement/PositionComponent.h"
#include "../MainPlayer/MainPlayerAccessSystem.h"
#include "../PositionsAndMovement/DistanceCalculator.h"
#include "InventoryComponent.h"

extern std::unique_ptr<ECSManager> ecsManager;
extern std::unique_ptr<EventBus> eventBus;

PlayerPickUpSystem::PlayerPickUpSystem(){
    requireComponent<PickupComponent>();
    listenToEvents();
}
void PlayerPickUpSystem::listenToEvents(){
    eventBus->listenToEvent<PlayerPickUpEvent>(this, &PlayerPickUpSystem::onPickup);
}
void PlayerPickUpSystem::onPickup(PlayerPickUpEvent& event){
    auto player = event.picker;
    auto playerPosition = ecsManager->getComponentFromEntity<PositionComponent>(player).getPosition();
    auto playerSize = ecsManager->getComponentFromEntity<TextComponent>(player).getSurfaceSize();

    for(auto pickupEntity: getRelevantEntities()){
        auto pickupPosition = ecsManager->getComponentFromEntity<PositionComponent>(pickupEntity).getPosition();
        auto pickupSize = ecsManager->getComponentFromEntity<TextComponent>(pickupEntity).getSurfaceSize();

        if (DistanceCalculator::isInAllowedRange(playerPosition, pickupPosition, playerSize, pickupSize, PICKUP_RANGE)){
            auto& playerInventory = ecsManager->getComponentFromEntity<InventoryComponent>(player);
            playerInventory.items.push_back(pickupEntity);
        }
    }

}