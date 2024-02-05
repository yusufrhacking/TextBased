#include "PlatformLandingSystem.h"
#include "../HighLevel/ECSManager.h"
#include "../Platformer/ProspectivePlatformLandingEvent.h"
#include "../Gravity/JumpingComponent.h"
#include <stdexcept>

#include "../PositionsAndMovement/VelocityComponent.h"

extern std::unique_ptr<ECSManager> ecsManager;
extern std::unique_ptr<EventBus> eventBus;

PlatformLandingSystem::PlatformLandingSystem() {
    listenToEvents();
}

void PlatformLandingSystem::listenToEvents() {
    eventBus->listenToEvent<ProspectivePlatformLandingEvent>(this, &PlatformLandingSystem::onProspectiveLanding);
}

void PlatformLandingSystem::onProspectiveLanding(ProspectivePlatformLandingEvent& event) {
    handlePhysics(event.a);
    handlePhysics(event.b);
}

void PlatformLandingSystem::handlePhysics(Entity entity) {
    if(ecsManager->hasComponent<JumpingComponent>(entity)) {
        ecsManager->getComponentFromEntity<JumpingComponent>(entity).onGround = true;
    }

    if(ecsManager->hasComponent<VelocityComponent>(entity)) {
        auto& velocity = ecsManager->getComponentFromEntity<VelocityComponent>(entity).velocity;
        if (velocity.y < 0) {
            spdlog::info("Zeroing velocity that was negative!");
        }
        velocity.y = 0;
    }
}

