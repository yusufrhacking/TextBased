#include "PickupSystem.h"
#include "../HighLevel/ECSManager.h"
#include "PickupEvent.h"
#include "../PositionsAndMovement/PositionComponent.h"

extern std::unique_ptr<ECSManager> ecsManager;
extern std::unique_ptr<EventBus> eventBus;

PickupSystem::PickupSystem(){
    requireComponent<MainPlayerComponent>();
    listenToEvents();
}
void PickupSystem::listenToEvents(){
    eventBus->listenToEvent<PickupEvent>(this, &PickupSystem::onPickup);
}
void PickupSystem::onPickup(PickupEvent& event){
    auto playerPosition = getMainPlayerPosition();

}

Position PickupSystem::getMainPlayerPosition() {
    auto mainPlayer = *getRelevantEntities().begin();
    return ecsManager->getComponentFromEntity<PositionComponent>(mainPlayer).getPosition();
}
