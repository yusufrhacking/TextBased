#include "CollisionHandleSystem.h"
#include "../../Design/Managers/ECSManager.h"

extern std::unique_ptr<ECSManager> ecsManager;

void CollisionHandleSystem::onCollision(CollisionEvent &event) {
    printf("Here\n");
    ecsManager->killEntity(event.a);
    ecsManager->killEntity(event.b);
}

void CollisionHandleSystem::listenToEvents(std::shared_ptr<EventBus> eventBus) {
    eventBus->listenToEvent<CollisionEvent>(this, &CollisionHandleSystem::onCollision);
}

void CollisionHandleSystem::update(std::shared_ptr<EventBus> eventBus) {

}
