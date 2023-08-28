#include <spdlog/spdlog.h>
#include "MovementHandleSystem.h"
#include "../../Design/Managers/ECSManager.h"

extern std::unique_ptr<ECSManager> ecsManager;
extern std::unique_ptr<EventBus> eventBus;

MovementHandleSystem::MovementHandleSystem(){
    listenToEvents();
}
void MovementHandleSystem::listenToEvents(){
    eventBus->listenToEvent<MovementEvent>(this, &MovementHandleSystem::onMovement);
}
void MovementHandleSystem::onMovement(MovementEvent& event){
    auto& position = ecsManager->getComponentFromEntity<PositionComponent>(event.entity);
    position.changePosition(event.change.xVelocity, event.change.yVelocity);
    spdlog::trace("Entity {} moved {}, {} to {}, {}", event.entity.getId(), event.change.xVelocity, event.change.yVelocity, position.getPosition().xPos, position.getPosition().yPos);
}