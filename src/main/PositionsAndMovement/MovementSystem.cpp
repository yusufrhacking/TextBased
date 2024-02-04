#include <spdlog/spdlog.h>
#include "MovementSystem.h"

#include "CollisionCheckSystem.h"
#include "ReadyToMoveEvent.h"

extern std::unique_ptr<ECSManager> ecsManager;
extern std::unique_ptr<EventBus> eventBus;


MovementSystem::MovementSystem() {
    unprocessedMovements = std::make_unique<std::vector<UnprocessedMovement>>();
    ecsManager->addSystem<CollisionCheckSystem>();
}

void MovementSystem::queueMovement(UnprocessedMovement movement) {
    unprocessedMovements->push_back(movement);
}

void MovementSystem::update(double deltaTime) {
    buildTotalChange();
    runXMotion(deltaTime);
    runYMotion(deltaTime);
    unprocessedMovements->clear();
    totalChangeForEntities.clear();
    spdlog::trace("Done processing movements");
}


void MovementSystem::runXMotion(double deltaTime) {
    for (const auto& changes : totalChangeForEntities) {
        int entityID = changes.first;
        const Velocity& velocity = changes.second;
        spdlog::trace("Emitting event for entity {} to velocity {}, {}", entityID, velocity.x, 0);
        eventBus->emitEvent<ReadyToMoveEvent>(Entity(entityID), velocity.x, 0);
    }
    ecsManager->getSystem<CollisionCheckSystem>().update(deltaTime);
}

void MovementSystem::runYMotion(double deltaTime) {
    for (const auto& changes : totalChangeForEntities) {
        int entityID = changes.first;
        const Velocity& velocity = changes.second;
        spdlog::trace("Emitting event for entity {} to velocity {}, {}", entityID, 0, velocity.y);
        eventBus->emitEvent<ReadyToMoveEvent>(Entity(entityID), 0, velocity.y);
    }
    ecsManager->getSystem<CollisionCheckSystem>().update(deltaTime);
}

void MovementSystem::buildTotalChange() {
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
}

