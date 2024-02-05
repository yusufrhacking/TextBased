#include "PlatformLandingSystem.h"
#include "../HighLevel/ECSManager.h"
#include "../Platformer/ProspectivePlatformLandingEvent.h"
#include "../Gravity/JumpingComponent.h"
#include <stdexcept>

#include "HorizontalPlatformMovementComponent.h"
#include "PlatformComponent.h"
#include "../Abyz/AbyzComponent.h"
#include "../PositionsAndMovement/PositionComponent.h"
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

    if (ecsManager->hasComponent<AbyzComponent>(event.a)) {
        if (ecsManager->hasComponent<PlatformComponent>(event.b)) {
            lockAbyzToPlatform(event.a, event.b);
        }
    }
    if (ecsManager->hasComponent<AbyzComponent>(event.b)) {
        if (ecsManager->hasComponent<PlatformComponent>(event.a)) {
            lockAbyzToPlatform(event.b, event.a);
        }
    }

}


void PlatformLandingSystem::lockAbyzToPlatform(Entity abyz, Entity platform) {
    auto platformPosition = ecsManager->getComponentFromEntity<PositionComponent>(platform).getPosition();
    auto platformSize = ecsManager->getComponentFromEntity<TextComponent>(platform).getSurfaceSize();
    auto abyzSize = ecsManager->getComponentFromEntity<TextComponent>(abyz).getSurfaceSize();

    auto leftBound = static_cast<unsigned int>(platformPosition.x);
    auto rightBound = static_cast<int>(platformPosition.x) + platformSize.width - abyzSize.width;

    ecsManager->addComponentToEntity<HorizontalPlatformMovementComponent>(abyz, leftBound, rightBound);
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



