#include "CollisionHandleSystem.h"
#include "../../Design/Managers/ECSManager.h"

extern std::unique_ptr<ECSManager> ecsManager;
extern std::unique_ptr<EventBus> eventBus;

CollisionHandleSystem::CollisionHandleSystem() {
    requireComponent<CollisionComponent>();
    listenToEvents();
}

void CollisionHandleSystem::onCollision(CollisionEvent &event) {
    printf("Here\n");
    ecsManager->killEntity(event.a);
    ecsManager->killEntity(event.b);
}

void CollisionHandleSystem::listenToEvents() {
    eventBus->listenToEvent<CollisionEvent>(this, &CollisionHandleSystem::onCollision);
}
