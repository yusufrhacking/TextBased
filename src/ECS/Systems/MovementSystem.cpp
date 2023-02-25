#include "MovementSystem.h"

void MovementSystem::update() {
    // Loop all entities the system cares about
    for (Entity entity: getEntities()){
        auto& position = manager.getComponent<PositionComponent>(entity);
        const auto movement = manager.getComponent<MovementComponent>(entity);

        position.position->xPos += movement.velocity->xVelocity;
        position.position->yPos += movement.velocity->yVelocity;

        spdlog::info(
                "Entity " + std::to_string(entity.getId())
                + " is at " + std::to_string(position.position->xPos)
                + ", " + std::to_string(position.position->yPos));
    }
}

MovementSystem::MovementSystem(ECSManager &manager) : manager(manager) {
    requireComponent<PositionComponent>();
    requireComponent<MovementComponent>();
    manager = ECSManager::getInstance();
    //requireComponent<PositionComponent>();

}
