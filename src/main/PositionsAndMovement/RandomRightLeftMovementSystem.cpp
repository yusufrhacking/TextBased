#include "RandomRightLeftMovementSystem.h"

#include "PositionComponent.h"
#include "../HighLevel/ECSManager.h"
#include "MovementSystem.h"
#include "RandomRightLeftMovementComponent.h"

extern std::unique_ptr<ECSManager> ecsManager;


RandomRightLeftMovementSystem::RandomRightLeftMovementSystem() {
    requireComponent<RandomRightLeftMovementComponent>();
    requireComponent<PositionComponent>();
    requireComponent<TextComponent>();
}

void RandomRightLeftMovementSystem::swapDirection(std::chrono::steady_clock::time_point now, RandomRightLeftMovementComponent& movementComponent) {
    movementComponent.moveDirection = generateRandomDirection();
    movementComponent.lastSwap = now;
    timeBeforeSwapinSec = std::uniform_real_distribution<>(timeBeforeSwapinSec - 0.8, timeBeforeSwapinSec + 0.8)(rng);
}

void RandomRightLeftMovementSystem::update(double deltaTime) {
    using namespace std::chrono;
    auto now = high_resolution_clock::now();

    for(auto entity: getRelevantEntities()) {
        auto& movementComponent = ecsManager->getComponentFromEntity<RandomRightLeftMovementComponent>(entity);
        float movementDistance = movementComponent.movementDistance;

        auto durationSinceChange = duration_cast<seconds>(now - movementComponent.lastSwap);

        if (durationSinceChange.count() >= timeBeforeSwapinSec) {
            swapDirection(now, movementComponent);
        }

        auto position = ecsManager->getComponentFromEntity<PositionComponent>(entity).getPosition();

        if (((int)position.x % Window::windowWidth) <= 50 || ((int)position.x % Window::windowWidth) >= (Window::windowWidth - 50)) {
            swapDirection(now, movementComponent);
        }

        float xChange = movementComponent.moveDirection * movementDistance * deltaTime;

        ecsManager->getSystem<MovementSystem>().queueMovement(UnprocessedMovement(entity, xChange, 0));
    }
}
