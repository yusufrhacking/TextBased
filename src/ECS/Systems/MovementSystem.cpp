#include "MovementSystem.h"

extern std::unique_ptr<ECSManager> ecsManager;

void MovementSystem::update(double deltaTime) {
    for (Entity entity: getReleventEntities()){
        auto& position = ecsManager->getComponent<TransformComponent>(entity);
        const auto movement = ecsManager->getComponent<MovementComponent>(entity);

        double xChange = movement.velocity->xVelocity * deltaTime;
        double yChange = movement.velocity->yVelocity * deltaTime;
        position.position->xPos += (float)xChange;
        position.position->yPos += (float)yChange;

        spdlog::debug(
                "Entity " + std::to_string(entity.getId())
                + " is at " + std::to_string(position.position->xPos)
                + ", " + std::to_string(position.position->yPos));
    }
}

MovementSystem::MovementSystem(){
    requireComponent<TransformComponent>();
    requireComponent<MovementComponent>();
}
