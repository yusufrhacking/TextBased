#include "CollisionHandleSystem.h"
#include "../HighLevel/ECSManager.h"
#include "CollisionComponent.h"
#include "PositionComponent.h"
#include "../MainPlayer/TiedChildComponent.h"
#include "LiveComponent.h"
#include "../Gravity/JumpingComponent.h"
#include <stdexcept>

#include "RightLeftCollisionEvent.h"
#include "TopBottomCollisionEvent.h"
#include "VelocityComponent.h"
#include "../Platformer/ProspectivePlatformLandingEvent.h"

extern std::unique_ptr<ECSManager> ecsManager;
extern std::unique_ptr<EventBus> eventBus;

CollisionHandleSystem::CollisionHandleSystem() {
    requireComponent<CollisionComponent>();
    requireComponent<LiveComponent>();
    listenToEvents();
}



void CollisionHandleSystem::onCollision(CollisionEvent &event) {
    auto entityA = event.a;

    auto entityB = event.b;

    // Check if top-bottom collision?
    auto aPosition = ecsManager->getComponentFromEntity<PositionComponent>(entityA).getPosition();
    auto bPosition = ecsManager->getComponentFromEntity<PositionComponent>(entityB).getPosition();

    auto aSize = ecsManager->getComponentFromEntity<TextComponent>(entityA).getSurfaceSize();
    auto bSize = ecsManager->getComponentFromEntity<TextComponent>(entityB).getSurfaceSize();

    float acceptableRange = 1.0;

    //Check Top Bottom Collisions
    if (aPosition.y <= bPosition.y - bSize.height + acceptableRange) {
        eventBus->emitEvent<TopBottomCollisionEvent>(entityA, entityB);
    }
    if (bPosition.y <= aPosition.y - aSize.height + acceptableRange) {
        eventBus->emitEvent<TopBottomCollisionEvent>(entityB, entityA);
    }

    //Check Left Right Collisions
    if (aPosition.x >= bPosition.x + bSize.width - acceptableRange) {
        eventBus->emitEvent<RightLeftCollisionEvent>(entityA, entityB);
    }
    if (bPosition.x >= aPosition.x + aSize.width - acceptableRange) {
        eventBus->emitEvent<RightLeftCollisionEvent>(entityB, entityA);
    }

    handleCollision(entityA);
    handleCollision(entityB);

    eventBus->emitEvent<ProspectivePlatformLandingEvent>(entityA, entityB);
}

void CollisionHandleSystem::handleCollision(Entity entity) {
    auto& positionComponent = ecsManager->getComponentFromEntity<PositionComponent>(entity);
    positionComponent.revertPosition();
}


void CollisionHandleSystem::listenToEvents() {
    eventBus->listenToEvent<CollisionEvent>(this, &CollisionHandleSystem::onCollision);
}


