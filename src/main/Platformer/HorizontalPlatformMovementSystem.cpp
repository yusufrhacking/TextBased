#include "HorizontalPlatformMovementSystem.h"

#include "HorizontalPlatformMovementComponent.h"
#include "../PositionsAndMovement/PositionComponent.h"

#include "../HighLevel/ECSManager.h"
#include "../PositionsAndMovement/MovementSystem.h"

extern std::unique_ptr<ECSManager> ecsManager;

HorizontalPlatformMovementSystem::HorizontalPlatformMovementSystem() {
    requireComponent<PositionComponent>();
    requireComponent<HorizontalPlatformMovementComponent>();
    requireComponent<TextComponent>();
}

void HorizontalPlatformMovementSystem::update(double deltaTime) {
    for(auto entity: getRelevantEntities()) {
        auto& movementComponent = ecsManager->getComponentFromEntity<HorizontalPlatformMovementComponent>(entity);
        float movementDistance = movementComponent.movementDistance;
        auto position = ecsManager->getComponentFromEntity<PositionComponent>(entity).getPosition();
        auto width = ecsManager->getComponentFromEntity<TextComponent>(entity).getSurfaceSize().width;

        if (position.x < movementComponent.leftBound) {
            movementComponent.moveDirection = 1;
            spdlog::info("Position x: {}", position.x);
            spdlog::info("Left Bound: {}", movementComponent.leftBound);
        } else if (position.x > movementComponent.rightBound) {
            movementComponent.moveDirection = -1;
            spdlog::info("Position x: {}", position.x);
            spdlog::info("Right Bound: {}", movementComponent.rightBound);
        }

        float xChange = movementComponent.moveDirection * movementDistance * deltaTime;

        ecsManager->getSystem<MovementSystem>().queueMovement(UnprocessedMovement(entity, xChange, 0));
    }
}
