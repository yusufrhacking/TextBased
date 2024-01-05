#include "CollisionHandleSystem.h"
#include "../HighLevel/ECSManager.h"
#include "CollisionComponent.h"
#include "PositionComponent.h"
#include "../MainPlayer/TiedChildComponent.h"
#include "LiveComponent.h"
#include "../Gravity/JumpingComponent.h"
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
    auto& positionComponent = ecsManager->getComponentFromEntity<PositionComponent>(entity);
    positionComponent.revertPosition();
    if(ecsManager->hasComponent<JumpingComponent>(entity)) {
        ecsManager->getComponentFromEntity<JumpingComponent>(entity).onGround = true;
    }

    if(ecsManager->hasComponent<VelocityComponent>(entity)) {
        auto& velocity = ecsManager->getComponentFromEntity<VelocityComponent>(entity).velocity;
        if (velocity.y < 0) {
            spdlog::info("Zeroing velocity that was negative!");
        }
        velocity.y = 0;
    }
}


void CollisionHandleSystem::listenToEvents() {
    eventBus->listenToEvent<CollisionEvent>(this, &CollisionHandleSystem::onCollision);
}


