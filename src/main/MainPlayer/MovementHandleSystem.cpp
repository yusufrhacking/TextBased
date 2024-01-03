#include <spdlog/spdlog.h>
#include "TiedChildComponent.h"
#include "MovementHandleSystem.h"
#include "../HighLevel/ECSManager.h"
#include "../PositionsAndMovement/PositionComponent.h"
#include "../PositionsAndMovement/PostMovementEvent.h"

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
    position.shiftPosition(change.x, change.y);

    if (ecsManager->hasComponent<TiedChildComponent>(entity)){
        auto& children = ecsManager->getComponentFromEntity<TiedChildComponent>(entity).entities;
        for (auto child : children){
            auto& childPosition = ecsManager->getComponentFromEntity<PositionComponent>(child);
            childPosition.shiftPosition(change.x, change.y);
        }
    }

    spdlog::trace("Entity {} moved {}, {} to {}, {}", entity.getId(), change.x, change.y, position.getPosition().x, position.getPosition().y);
    eventBus->emitEvent<PostMovementEvent>(entity, change);
}