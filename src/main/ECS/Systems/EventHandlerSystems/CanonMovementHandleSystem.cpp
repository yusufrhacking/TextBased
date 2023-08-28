#include "CanonMovementHandleSystem.h"
#include <mach/mach_types.h>
#include <spdlog/spdlog.h>
#include "../../Design/Managers/ECSManager.h"
#include "../../../Helpers/EventSystem/Events/PreMovementEvent.h"

extern std::unique_ptr<ECSManager> ecsManager;
extern std::unique_ptr<EventBus> eventBus;

CanonMovementHandleSystem::CanonMovementHandleSystem(Canon& canon): canon(canon){
    listenToEvents();
}
void CanonMovementHandleSystem::listenToEvents(){
    eventBus->listenToEvent<PreMovementEvent>(this, &CanonMovementHandleSystem::onMovement);
}
void CanonMovementHandleSystem::onMovement(PreMovementEvent& event){
    auto& change = event.change;
    auto entity = event.entity;
    auto futurePosition = ecsManager->getComponentFromEntity<PositionComponent>(entity);
    auto oldMapPosition = futurePosition.getMapPosition();
    futurePosition.shiftPosition(change.xVelocity, change.yVelocity);//See where it will be
    if (futurePosition.getMapPosition() != oldMapPosition){
        canon.removeEntityFromPage(entity, oldMapPosition);
        canon.placeEntity(entity, futurePosition.getMapPosition());
    }
    eventBus->emitEvent<ReadyToMoveEvent>(event);
}