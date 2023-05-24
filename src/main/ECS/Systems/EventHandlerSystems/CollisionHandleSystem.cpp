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
    if (ecsManager->hasComponent<MovementComponent>(event.a) || ecsManager->hasComponent<MainPlayerComponent>(event.a)){
        auto& position = ecsManager->getComponentFromEntity<PositionComponent>(event.a);
        const auto movement = ecsManager->getComponentFromEntity<MainPlayerComponent>(event.a);

        double xChange = movement.movementSpeed->xVelocity;
        double yChange = movement.movementSpeed->yVelocity;
        position.position->xPos -= (float)xChange;
        position.position->yPos -= (float)yChange;
    }
    if (ecsManager->hasComponent<MovementComponent>(event.b) || ecsManager->hasComponent<MainPlayerComponent>(event.b)){
        auto& position = ecsManager->getComponentFromEntity<PositionComponent>(event.b);
        const auto movement = ecsManager->getComponentFromEntity<MovementComponent>(event.b);

        double xChange = movement.velocity->xVelocity * event.deltaTime;
        double yChange = movement.velocity->yVelocity * event.deltaTime;
        position.position->xPos -= (float)xChange;
        position.position->yPos -= (float)yChange;
    }
//    ecsManager->killEntity(event.a);
//    ecsManager->killEntity(event.b);
}

void CollisionHandleSystem::listenToEvents() {
    eventBus->listenToEvent<CollisionEvent>(this, &CollisionHandleSystem::onCollision);
}
