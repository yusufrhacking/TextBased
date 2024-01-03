#include "GravitySystem.h"

#include "GravityComponent.h"
#include "VelocityComponent.h"
#include "../PositionsAndMovement/PositionComponent.h"
#include "../HighLevel/ECSManager.h"

extern std::unique_ptr<ECSManager> ecsManager;

GravitySystem::GravitySystem() {
    requireComponent<GravityComponent>();
    requireComponent<VelocityComponent>();
}

void GravitySystem::update(double deltaTime) {
    for(const auto& entity: getRelevantEntities()) {
        auto& velocityComponent = ecsManager->getComponentFromEntity<VelocityComponent>(entity);
        float newVelocity = velocityComponent.velocity.yVelocity + velocityForce*deltaTime;
        velocityComponent.velocity.yVelocity = std::ranges::min(newVelocity, terminalVelocity);
    }
}