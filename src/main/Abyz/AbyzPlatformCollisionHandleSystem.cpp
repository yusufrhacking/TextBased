#include "AbyzPlatformCollisionHandleSystem.h"

#include "AbyzComponent.h"
#include "../HighLevel/ECSManager.h"
#include "../MainPlayer/MainPlayerComponent.h"
#include "../Platformer/PlatformComponent.h"

extern std::unique_ptr<ECSManager> ecsManager;
extern std::unique_ptr<EventBus> eventBus;

AbyzPlatformCollisionHandleSystem::AbyzPlatformCollisionHandleSystem() {
    listenToEvents();
}

void AbyzPlatformCollisionHandleSystem::listenToEvents() {
    eventBus->listenToEvent<TopBottomCollisionEvent>(this, &AbyzPlatformCollisionHandleSystem::onTopBottomCollision);
}

void AbyzPlatformCollisionHandleSystem::onTopBottomCollision(TopBottomCollisionEvent& event) {
    if (ecsManager->hasComponent<PlatformComponent>(event.bottom)) {
        return;
    }
    if (ecsManager->hasComponent<PlatformComponent>(event.top)) {
        return;
    }

    spdlog::info("Non platform collision!");

    if (ecsManager->hasComponent<MainPlayerComponent>(event.top)) {
        if(ecsManager->hasComponent<AbyzComponent>(event.bottom)) {
            ecsManager->killEntity(event.bottom);
        }
    }
}
