#include "GravitySystem.h"

#include "GravityComponent.h"
#include "JumpingSystem.h"
#include "../PositionsAndMovement/VelocityComponent.h"
#include "../PositionsAndMovement/PositionComponent.h"
#include "../HighLevel/ECSManager.h"
#include "../PositionsAndMovement/LiveComponent.h"

extern std::unique_ptr<ECSManager> ecsManager;

GravitySystem::GravitySystem() {
    requireComponent<GravityComponent>();
    requireComponent<VelocityComponent>();
    requireComponent<LiveComponent>();
    ecsManager->addSystem<JumpingSystem>();
}

void GravitySystem::update(double deltaTime) {
    for(const auto& entity: getRelevantEntities()) {
        auto& velocityComponent = ecsManager->getComponentFromEntity<VelocityComponent>(entity);
        float newVelocity = velocityComponent.velocity.y + gravityForce*deltaTime;
        velocityComponent.velocity.y = std::ranges::min(newVelocity, terminalVelocity);
    }
    ecsManager->getSystem<JumpingSystem>().update();
}
