#include "CollisionHandleSystem.h"
#include "../../Design/Managers/ECSManager.h"
#include "../../Components/MainPlayerComponent.h"

extern std::unique_ptr<ECSManager> ecsManager;
extern std::unique_ptr<EventBus> eventBus;

CollisionHandleSystem::CollisionHandleSystem() {
    requireComponent<CollisionComponent>();
    listenToEvents();
}

void CollisionHandleSystem::onCollision(CollisionEvent &event) {
    if (!ecsManager->hasComponent<MainPlayerComponent>(event.a)){
        ecsManager->killEntity(event.a);
    }
    if (!ecsManager->hasComponent<MainPlayerComponent>(event.b)){
        ecsManager->killEntity(event.b);
    }
}

void CollisionHandleSystem::listenToEvents() {
    eventBus->listenToEvent<CollisionEvent>(this, &CollisionHandleSystem::onCollision);
}
