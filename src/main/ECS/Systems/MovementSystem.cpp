#include "MovementSystem.h"

extern std::unique_ptr<ECSManager> ecsManager;

MovementSystem::MovementSystem(){
    requireComponent<PositionComponent>();
    requireComponent<MovementComponent>();
}

void MovementSystem::update(double deltaTime) {
    for (Entity entity: getRelevantEntities()){
        auto& position = ecsManager->getComponentFromEntity<PositionComponent>(entity);
        const auto movement = ecsManager->getComponentFromEntity<MovementComponent>(entity);

        double xChange = movement.velocity->xVelocity * deltaTime;
        double yChange = movement.velocity->yVelocity * deltaTime;
        position.position->xPos += (float)xChange;
        position.position->yPos += (float)yChange;
    }
}

