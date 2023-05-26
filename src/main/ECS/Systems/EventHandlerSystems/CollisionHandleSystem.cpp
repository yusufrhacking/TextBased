#include "CollisionHandleSystem.h"
#include "../../Design/Managers/ECSManager.h"
#include "../../Components/MainPlayerComponent.h"
#include "../../Components/MovementComponent.h"

extern std::unique_ptr<ECSManager> ecsManager;
extern std::unique_ptr<EventBus> eventBus;

CollisionHandleSystem::CollisionHandleSystem() {
    requireComponent<CollisionComponent>();
    listenToEvents();
}

void CollisionHandleSystem::onCollision(CollisionEvent &event) {
    ecsManager->getComponentFromEntity<PositionComponent>(event.offender).revertPosition();
}

void CollisionHandleSystem::listenToEvents() {
    eventBus->listenToEvent<CollisionEvent>(this, &CollisionHandleSystem::onCollision);
}
