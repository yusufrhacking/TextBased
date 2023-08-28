#include <spdlog/spdlog.h>
#include "MovementHandleSystem.h"
#include "../../Design/Managers/ECSManager.h"

extern std::unique_ptr<ECSManager> ecsManager;
extern std::unique_ptr<EventBus> eventBus;

MovementHandleSystem::MovementHandleSystem(){
    listenToEvents();
}
void MovementHandleSystem::listenToEvents(){
    eventBus->listenToEvent<ReadyToMoveEvent>(this, &MovementHandleSystem::onMovement);
}
void MovementHandleSystem::onMovement(ReadyToMoveEvent& event){
    auto& change = event.change;
    auto entity = event.entity;
    auto& position = ecsManager->getComponentFromEntity<PositionComponent>(entity);
    auto oldMapPosition = position.getMapPosition();
    position.shiftPosition(change.xVelocity, change.yVelocity);
    spdlog::trace("Entity {} moved {}, {} to {}, {}", entity.getId(), change.xVelocity, change.yVelocity, position.getPosition().xPos, position.getPosition().yPos);
}