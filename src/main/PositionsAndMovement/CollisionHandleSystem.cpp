#include "CollisionHandleSystem.h"
#include "../HighLevel/ECSManager.h"
#include "CollisionComponent.h"
#include "PositionComponent.h"

extern std::unique_ptr<ECSManager> ecsManager;
extern std::unique_ptr<EventBus> eventBus;

CollisionHandleSystem::CollisionHandleSystem() {
    requireComponent<CollisionComponent>();
    listenToEvents();
}

void CollisionHandleSystem::onCollision(CollisionEvent &event) {
    auto aPositionComponent = ecsManager->getComponentFromEntity<PositionComponent>(event.a);
    auto aLastFrameMoved = aPositionComponent.getFrameLastMoved();

    auto bPositionComponent = ecsManager->getComponentFromEntity<PositionComponent>(event.b);
    auto bLastFrameMoved = bPositionComponent.getFrameLastMoved();

    if (aLastFrameMoved > bLastFrameMoved){
        aPositionComponent.revertPosition();
    } else if (aLastFrameMoved == bLastFrameMoved){
        aPositionComponent.revertPosition();
        bPositionComponent.revertPosition();
    } else{
        bPositionComponent.revertPosition();
    }
}


Entity CollisionHandleSystem::findOffender(Entity a, Entity b) {
    auto aPositionComponent = ecsManager->getComponentFromEntity<PositionComponent>(a);
    auto aLastFrameMoved = aPositionComponent.getFrameLastMoved();

    auto bPositionComponent = ecsManager->getComponentFromEntity<PositionComponent>(b);
    auto bLastFrameMoved = bPositionComponent.getFrameLastMoved();

    if (aLastFrameMoved > bLastFrameMoved){
        return a;
    }else{
        return b;
    }
}

Entity CollisionHandleSystem::findDefender(Entity a, Entity b) {
    auto aPositionComponent = ecsManager->getComponentFromEntity<PositionComponent>(a);
    auto aLastFrameMoved = aPositionComponent.getFrameLastMoved();

    auto bPositionComponent = ecsManager->getComponentFromEntity<PositionComponent>(b);
    auto bLastFrameMoved = bPositionComponent.getFrameLastMoved();

    if (aLastFrameMoved < bLastFrameMoved){
        return a;
    } else{
        return b;
    }
}

float CollisionHandleSystem::getMovementTotal(Entity entity) {
    auto positionComponent = ecsManager->getComponentFromEntity<PositionComponent>(entity);
    auto currentPos = positionComponent.getPosition();
    auto previousPos = positionComponent.getPreviousPosition();

    float xChange = currentPos.xPos - previousPos.xPos;
    float yChange = currentPos.yPos - previousPos.yPos;
    return abs(xChange)+abs(yChange);
}

void CollisionHandleSystem::listenToEvents() {
    eventBus->listenToEvent<CollisionEvent>(this, &CollisionHandleSystem::onCollision);
}
