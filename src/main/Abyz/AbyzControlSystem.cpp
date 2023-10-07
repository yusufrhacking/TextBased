#include "AbyzControlSystem.h"
#include "AbyzComponent.h"
#include "../PositionsAndMovement/PositionComponent.h"
#include "../HighLevel/ECSManager.h"
#include <random>
#include <chrono>

extern std::unique_ptr<ECSManager> ecsManager;

const int DIRECTION_CHANGE_FREQUENCY = 5;


AbyzControlSystem::AbyzControlSystem() {
    requireComponent<AbyzComponent>();
    requireComponent<PositionComponent>();
}

void AbyzControlSystem::update(double deltaTime) {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<int> distribution(0, 100);

    for (Entity entity : getRelevantEntities()) {
        auto& position = ecsManager->getComponentFromEntity<PositionComponent>(entity);
        auto& abyz = ecsManager->getComponentFromEntity<AbyzComponent>(entity);

        if (distribution(generator) % 100 < DIRECTION_CHANGE_FREQUENCY) {
            std::uniform_real_distribution<float> floatDistribution(-1.0f, 1.0f);

            abyz.directionX = floatDistribution(generator);
            abyz.directionY = floatDistribution(generator);
        }

        auto xChange = abyz.directionX * abyz.speed * deltaTime;
        auto yChange = abyz.directionY * abyz.speed * deltaTime;

        position.shiftPosition(xChange, yChange);
    }
}