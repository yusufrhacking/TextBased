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

        if (position.x < movementComponent.leftBound || position.x > movementComponent.rightBound) {
            movementComponent.moveDirection *= -1;
        }

        float xChange = movementComponent.moveDirection * movementDistance * deltaTime;

        ecsManager->getSystem<MovementSystem>().queueMovement(UnprocessedMovement(entity, xChange, 0));
    }
}
