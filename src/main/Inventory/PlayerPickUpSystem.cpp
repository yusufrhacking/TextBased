#include "PlayerPickUpSystem.h"
#include "../HighLevel/ECSManager.h"
#include "PickupComponent.h"
#include "PlayerPickUpEvent.h"
#include "../PositionsAndMovement/PositionComponent.h"

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
//    auto mainPlayer = *getRelevantEntities().begin();
//    auto playerPosition = ecsManager->getComponentFromEntity<PositionComponent>(mainPlayer).getPosition();
//    auto playerSize = ecsManager->getComponentFromEntity<TextComponent>(mainPlayer).getSurfaceSize();

    for(auto pickupEntity: getRelevantEntities()){
        auto pickupPosition = ecsManager->getComponentFromEntity<PositionComponent>(pickupEntity).getPosition();
        auto pickupSize = ecsManager->getComponentFromEntity<TextComponent>(pickupEntity).getSurfaceSize();
    }

}

Position PlayerPickUpSystem::getMainPlayerPosition() {
    auto mainPlayer = *getRelevantEntities().begin();
    return ecsManager->getComponentFromEntity<PositionComponent>(mainPlayer).getPosition();
}
