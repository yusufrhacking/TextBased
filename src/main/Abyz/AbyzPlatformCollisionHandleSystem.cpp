#include "AbyzPlatformCollisionHandleSystem.h"

#include "AbyzComponent.h"
#include "../HighLevel/ECSManager.h"
#include "../MainPlayer/MainPlayerComponent.h"
#include "../Platformer/PlatformComponent.h"
#include "../PositionsAndMovement/RightLeftCollisionEvent.h"

extern std::unique_ptr<ECSManager> ecsManager;
extern std::unique_ptr<EventBus> eventBus;

AbyzPlatformCollisionHandleSystem::AbyzPlatformCollisionHandleSystem() {
    listenToEvents();
}

void AbyzPlatformCollisionHandleSystem::listenToEvents() {
    eventBus->listenToEvent<TopBottomCollisionEvent>(this, &AbyzPlatformCollisionHandleSystem::onTopBottomCollision);
    eventBus->listenToEvent<RightLeftCollisionEvent>(this, &AbyzPlatformCollisionHandleSystem::onRightLeftCollision);
}

void AbyzPlatformCollisionHandleSystem::onTopBottomCollision(TopBottomCollisionEvent& event) {
    if (ecsManager->hasComponent<MainPlayerComponent>(event.top)) {
        if(ecsManager->hasComponent<AbyzComponent>(event.bottom)) {
            ecsManager->killEntity(event.bottom);
        }
    }
}

void AbyzPlatformCollisionHandleSystem::onRightLeftCollision(RightLeftCollisionEvent& event) {
    if (ecsManager->hasComponent<MainPlayerComponent>(event.left)) {
        if(ecsManager->hasComponent<AbyzComponent>(event.right)) {
            // ecsManager->killEntity(event.left);
        }
    }
    if (ecsManager->hasComponent<MainPlayerComponent>(event.right)) {
        if(ecsManager->hasComponent<AbyzComponent>(event.left)) {
            // ecsManager->killEntity(event.right);
        }
    }
}
