#include <spdlog/spdlog.h>
#include "UnprocessedMovementSystem.h"

#include "../PositionsAndMovement/CollisionCheckSystem.h"
#include "../PositionsAndMovement/ReadyToMoveEvent.h"

extern std::unique_ptr<ECSManager> ecsManager;
extern std::unique_ptr<EventBus> eventBus;


UnprocessedMovementSystem::UnprocessedMovementSystem() {
    unprocessedMovements = std::make_unique<std::vector<UnprocessedMovement>>();
    ecsManager->addSystem<CollisionCheckSystem>();
}

void UnprocessedMovementSystem::queueMovement(UnprocessedMovement movement) {
    unprocessedMovements->push_back(movement);
}

void UnprocessedMovementSystem::update(double deltaTime) {
    for (auto unprocessedMovement : *unprocessedMovements) {
        int entity = unprocessedMovement.entity.getId();
        if (totalChangeForEntities.count(entity) > 0) {
            Velocity& existingVelocity = totalChangeForEntities[entity];
            existingVelocity.x += unprocessedMovement.xChange;
            existingVelocity.y += unprocessedMovement.yChange;
        } else {
            Velocity velocity;
            velocity.x = unprocessedMovement.xChange;
            velocity.y = unprocessedMovement.yChange;
            totalChangeForEntities[entity] = velocity;
        }
    }


    for (const auto& changes : totalChangeForEntities) {
        int entityID = changes.first;
        const Velocity& velocity = changes.second;
        spdlog::trace("Emitting event for entity {} to velocity {}, {}", entityID, velocity.x, velocity.y);
        eventBus->emitEvent<ReadyToMoveEvent>(Entity(entityID), velocity);
    }
    unprocessedMovements->clear();
    totalChangeForEntities.clear();
    spdlog::trace("Done processing movements");

    ecsManager->getSystem<CollisionCheckSystem>().update(deltaTime);
}

