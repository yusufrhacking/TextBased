#include "MovementSystem.h"

extern std::unique_ptr<ECSManager> ecsManager;

MovementSystem::MovementSystem(){
    requireComponent<PositionComponent>();
    requireComponent<MovementComponent>();
}

void MovementSystem::update(double deltaTime) {
    for (Entity entity: getReleventEntities()){
        auto& position = ecsManager->getComponent<PositionComponent>(entity);
        const auto movement = ecsManager->getComponent<MovementComponent>(entity);

        double xChange = movement.velocity->xVelocity * deltaTime;
        double yChange = movement.velocity->yVelocity * deltaTime;
        position.position->xPos += (float)xChange;
        position.position->yPos += (float)yChange;
    }
}

