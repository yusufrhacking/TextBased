#include "GravitySystem.h"

#include "GravityComponent.h"
#include "../PositionsAndMovement/VelocityComponent.h"
#include "../PositionsAndMovement/PositionComponent.h"
#include "../HighLevel/ECSManager.h"
#include "../PositionsAndMovement/LiveComponent.h"

extern std::unique_ptr<ECSManager> ecsManager;

GravitySystem::GravitySystem() {
    requireComponent<GravityComponent>();
    requireComponent<VelocityComponent>();
    requireComponent<LiveComponent>();
}

void GravitySystem::update(double deltaTime) {
    for(const auto& entity: getRelevantEntities()) {
        auto& velocityComponent = ecsManager->getComponentFromEntity<VelocityComponent>(entity);
        float newVelocity = velocityComponent.velocity.yVelocity + velocityForce*deltaTime;
        velocityComponent.velocity.yVelocity = std::ranges::min(newVelocity, terminalVelocity);
    }
}
