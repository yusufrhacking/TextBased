#include "CanonMovementHandleSystem.h"
#include <mach/mach_types.h>
#include <spdlog/spdlog.h>
#include "../HighLevel/ECSManager.h"
#include "../PositionsAndMovement/PositionComponent.h"

extern std::unique_ptr<ECSManager> ecsManager;
extern std::unique_ptr<EventBus> eventBus;

CanonMovementHandleSystem::CanonMovementHandleSystem(Canon& canon): canon(canon){
    listenToEvents();
}
void CanonMovementHandleSystem::listenToEvents(){
    eventBus->listenToEvent<PostMovementEvent>(this, &CanonMovementHandleSystem::onMovement);
}
void CanonMovementHandleSystem::onMovement(PostMovementEvent& event){
    auto& change = event.change;
    auto entity = event.entity;
    auto positionComponent = ecsManager->getComponentFromEntity<PositionComponent>(entity);
    auto oldMapPosition = positionComponent.getMapPosition();
    auto currPosition = positionComponent.getPosition();
    currPosition.x += (float)change.x;
    currPosition.y += (float)change.y;
    auto futureMapPosition = Canon::getMapPosition(currPosition);
    if (futureMapPosition != oldMapPosition){
        canon.removeEntityFromPage(entity, oldMapPosition);
        canon.placeEntity(entity, futureMapPosition);
    }
}