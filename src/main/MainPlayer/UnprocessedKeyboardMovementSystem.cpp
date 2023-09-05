#include <spdlog/spdlog.h>
#include "UnprocessedKeyboardMovementSystem.h"

extern std::unique_ptr<ECSManager> ecsManager;
extern std::unique_ptr<EventBus> eventBus;


UnprocessedKeyboardMovementSystem::UnprocessedKeyboardMovementSystem() {
    unprocessedMovements = std::make_unique<std::vector<UnprocessedMovement>>();
}

void UnprocessedKeyboardMovementSystem::queueMovement(UnprocessedMovement movement) {
    unprocessedMovements->push_back(movement);
}

void UnprocessedKeyboardMovementSystem::run() {
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
        eventBus->emitEvent<ReadyToMoveEvent>(Entity(entityID), velocity);
    }
    unprocessedMovements->clear();
    totalChangeForEntities.clear();
    spdlog::trace("Done processing movements");

}

