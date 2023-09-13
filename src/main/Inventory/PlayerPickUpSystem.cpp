#include "PlayerPickUpSystem.h"
#include "../HighLevel/ECSManager.h"
#include "PickupComponent.h"
#include "PlayerPickUpEvent.h"
#include "../PositionsAndMovement/PositionComponent.h"
#include "../MainPlayer/MainPlayerAccessSystem.h"
#include "../PositionsAndMovement/DistanceCalculator.h"

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
    auto mainPlayer = *ecsManager->getSystem<MainPlayerAccessSystem>().getRelevantEntities().begin();
    auto playerPosition = ecsManager->getComponentFromEntity<PositionComponent>(mainPlayer).getPosition();
    auto playerSize = ecsManager->getComponentFromEntity<TextComponent>(mainPlayer).getSurfaceSize();

    for(auto pickupEntity: getRelevantEntities()){
        auto pickupPosition = ecsManager->getComponentFromEntity<PositionComponent>(pickupEntity).getPosition();
        auto pickupSize = ecsManager->getComponentFromEntity<TextComponent>(pickupEntity).getSurfaceSize();

        if (DistanceCalculator::isInAllowedRange(playerPosition, pickupPosition, playerSize, pickupSize, PICKUP_RANGE)){
            spdlog::debug("Picking up the jawn");
        }
    }

}