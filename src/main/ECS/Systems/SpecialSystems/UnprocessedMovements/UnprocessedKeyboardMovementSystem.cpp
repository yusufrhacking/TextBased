#include <spdlog/spdlog.h>
#include "UnprocessedKeyboardMovementSystem.h"

extern std::unique_ptr<ECSManager> ecsManager;

UnprocessedKeyboardMovementSystem::UnprocessedKeyboardMovementSystem() {
    unprocessedMovements = std::make_unique<std::vector<UnprocessedMovement>>();
}

void UnprocessedKeyboardMovementSystem::queueMovement(UnprocessedMovement movement) {
    unprocessedMovements->push_back(movement);
}

void UnprocessedKeyboardMovementSystem::processMovement() {
    for (auto unprocessedMovement : *unprocessedMovements) {
        int entity = unprocessedMovement.entity.getId();
        if (totalChangeForEntities.count(entity) > 0) {
            Velocity& existingVelocity = totalChangeForEntities[entity];
            existingVelocity.xVelocity += unprocessedMovement.xChange;
            existingVelocity.yVelocity += unprocessedMovement.yChange;
        } else {
            Velocity velocity;
            velocity.xVelocity = unprocessedMovement.xChange;
            velocity.yVelocity = unprocessedMovement.yChange;
            totalChangeForEntities[entity] = velocity;
        }
    }
    spdlog::trace("Unprocessed Movements Tallied");
    for (const auto& changes : totalChangeForEntities) {
        int entityID = changes.first;
        const Velocity& velocity = changes.second;
        auto& position = ecsManager->getComponentFromEntity<PositionComponent>(Entity(entityID));
        position.changePosition(velocity.xVelocity, velocity.yVelocity);
        spdlog::trace("Entity {} moved {}, {}", entityID, velocity.xVelocity, velocity.yVelocity);
    }
    unprocessedMovements->clear();
    totalChangeForEntities.clear();
    spdlog::debug("Done processing movements");

}

