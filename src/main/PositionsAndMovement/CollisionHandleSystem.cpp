#include "CollisionHandleSystem.h"
#include "../HighLevel/ECSManager.h"
#include "CollisionComponent.h"
#include "PositionComponent.h"
#include "../MainPlayer/TiedChildComponent.h"
#include "LiveComponent.h"
#include <stdexcept>

#include "VelocityComponent.h"

extern std::unique_ptr<ECSManager> ecsManager;
extern std::unique_ptr<EventBus> eventBus;

CollisionHandleSystem::CollisionHandleSystem() {
    requireComponent<CollisionComponent>();
    requireComponent<LiveComponent>();
    listenToEvents();
}



void CollisionHandleSystem::onCollision(CollisionEvent &event) {
    float deltaTime = event.deltaTime;
    auto entityA = event.a;
    handleCollision(deltaTime, entityA);

    auto entityB = event.b;
    handleCollision(deltaTime, entityB);
}

void CollisionHandleSystem::handleCollision(float deltaTime, Entity entity) {
    if (!ecsManager->hasComponent<VelocityComponent>(entity)) {
        return;
    }

    auto& positionComponent = ecsManager->getComponentFromEntity<PositionComponent>(entity);
    auto& velocity = ecsManager->getComponentFromEntity<VelocityComponent>(entity).velocity;
    positionComponent.shiftPosition(-velocity.x * deltaTime, -velocity.y * deltaTime);

    velocity.y = 0;

}


void CollisionHandleSystem::listenToEvents() {
    eventBus->listenToEvent<CollisionEvent>(this, &CollisionHandleSystem::onCollision);
}


