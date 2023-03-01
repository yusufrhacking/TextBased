#include "MovementSystem.h"

extern std::unique_ptr<ECSManager> manager;

void MovementSystem::update(double deltaTime) {
    // Loop all entities the system cares about
    for (Entity entity: getEntities()){
        auto& position = manager->getComponent<PositionComponent>(entity);
        const auto movement = manager->getComponent<MovementComponent>(entity);

        double xChange = movement.velocity->xVelocity * deltaTime;
        double yChange = movement.velocity->yVelocity * deltaTime;
        position.position->xPos += xChange;
        position.position->yPos += yChange;

        spdlog::info(
                "Entity " + std::to_string(entity.getId())
                + " is at " + std::to_string(position.position->xPos)
                + ", " + std::to_string(position.position->yPos));
    }
}

MovementSystem::MovementSystem(){
    requireComponent<PositionComponent>();
    requireComponent<MovementComponent>();
    //requireComponent<PositionComponent>();

}
