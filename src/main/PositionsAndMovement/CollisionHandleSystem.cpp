#include "CollisionHandleSystem.h"
#include "../HighLevel/ECSManager.h"
#include "CollisionComponent.h"
#include "PositionComponent.h"
#include "../MainPlayer/TiedChildComponent.h"
#include "LiveComponent.h"
#include "../Gravity/JumpingComponent.h"
#include <stdexcept>

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
    handleCollision(entityA);

    auto entityB = event.b;
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


