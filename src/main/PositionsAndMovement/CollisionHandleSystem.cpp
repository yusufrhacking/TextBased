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
    auto& positionComponent = ecsManager->getComponentFromEntity<PositionComponent>(entityA);
    auto& velocity = ecsManager->getComponentFromEntity<VelocityComponent>(entityA).velocity;
    positionComponent.shiftPosition(-velocity.x * deltaTime, -velocity.y * deltaTime);

    if (ecsManager->hasComponent<VelocityComponent>(entityA)) {
        ecsManager->getComponentFromEntity<VelocityComponent>(entityA).velocity.y = 0;
    }

    auto entityB = event.b;
}


void CollisionHandleSystem::listenToEvents() {
    eventBus->listenToEvent<CollisionEvent>(this, &CollisionHandleSystem::onCollision);
}


