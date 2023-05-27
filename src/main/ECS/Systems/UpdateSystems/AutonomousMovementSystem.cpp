#include <spdlog/spdlog.h>
#include "AutonomousMovementSystem.h"
#include "CollisionCheckSystem.h"

extern std::unique_ptr<ECSManager> ecsManager;

AutonomousMovementSystem::AutonomousMovementSystem(){
    requireComponent<PositionComponent>();
    requireComponent<MovementComponent>();
}

void AutonomousMovementSystem::update(double deltaTime) {
    for (Entity entity: getRelevantEntities()){
        auto& position = ecsManager->getComponentFromEntity<PositionComponent>(entity);
        const auto movement = ecsManager->getComponentFromEntity<MovementComponent>(entity);

        double xChange = movement.velocity->xVelocity * deltaTime;
        double yChange = movement.velocity->yVelocity * deltaTime;

        position.changePosition(xChange, yChange);
        spdlog::trace("Entity {} moved {}, {} to {}, {}", entity.getId(), xChange, yChange, position.getPosition().xPos, position.getPosition().yPos);
    }
}

