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
    auto entityA = event.a;
    auto entityB = event.b;
}


void CollisionHandleSystem::listenToEvents() {
    eventBus->listenToEvent<CollisionEvent>(this, &CollisionHandleSystem::onCollision);
}


