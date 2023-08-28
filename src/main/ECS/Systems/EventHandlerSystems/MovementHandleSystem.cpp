#include <spdlog/spdlog.h>
#include "MovementHandleSystem.h"
#include "../../Design/Managers/ECSManager.h"

extern std::unique_ptr<ECSManager> ecsManager;
extern std::unique_ptr<EventBus> eventBus;

MovementHandleSystem::MovementHandleSystem(Canon& canon): canon(canon){
    listenToEvents();
}
void MovementHandleSystem::listenToEvents(){
    eventBus->listenToEvent<MovementEvent>(this, &MovementHandleSystem::onMovement);
}
void MovementHandleSystem::onMovement(MovementEvent& event){
    auto& change = event.change;
    auto entity = event.entity;
    auto& position = ecsManager->getComponentFromEntity<PositionComponent>(entity);
    auto oldMapPosition = position.getMapPosition();
    position.changePosition(change.xVelocity, change.yVelocity);
    if (position.getMapPosition() != oldMapPosition){
        canon.removeEntityFromPage(entity, oldMapPosition);
        canon.placeEntity(entity, position.getMapPosition());
    }
    spdlog::trace("Entity {} moved {}, {} to {}, {}", entity.getId(), change.xVelocity, change.yVelocity, position.getPosition().xPos, position.getPosition().yPos);
}