#include "AbyzControlSystem.h"
#include "AbyzComponent.h"
#include "../PositionsAndMovement/PositionComponent.h"
#include "../HighLevel/ECSManager.h"
#include "../MainPlayer/MainPlayerAccessSystem.h"
#include "../PositionsAndMovement/DistanceCalculator.h"
#include <random>
#include <chrono>

extern std::unique_ptr<ECSManager> ecsManager;

const int DIRECTION_CHANGE_FREQUENCY = 1;
const float ATTACK_RADIUS = 10;
const float DETECTION_MULTIPLIER = 10;
const float DETECTION_RADIUS = ATTACK_RADIUS * DETECTION_MULTIPLIER;

AbyzControlSystem::AbyzControlSystem() {
    requireComponent<AbyzComponent>();
    requireComponent<PositionComponent>();
    requireComponent<TextComponent>();
}

void AbyzControlSystem::update(double deltaTime) {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<int> distribution(0, 100);

    Entity mainPlayer = ecsManager->getSystem<MainPlayerAccessSystem>().getMainPlayer();
    Position playerPosition = ecsManager->getComponentFromEntity<PositionComponent>(mainPlayer).getPosition();
    Size playerSize = ecsManager->getComponentFromEntity<TextComponent>(mainPlayer).getSurfaceSize();

    for (Entity entity : getRelevantEntities()) {
        auto& positionComponent = ecsManager->getComponentFromEntity<PositionComponent>(entity);
        auto position = positionComponent.getPosition();
        auto size = ecsManager->getComponentFromEntity<TextComponent>(entity).getSurfaceSize();
        auto& abyz = ecsManager->getComponentFromEntity<AbyzComponent>(entity);

        bool isInDetectionRange = DistanceCalculator::isInAllowedRange(playerPosition, position, playerSize, size, DETECTION_RADIUS);
        bool isInAttackRange = DistanceCalculator::isInAllowedRange(playerPosition, position, playerSize, size, ATTACK_RADIUS);


        switch (abyz.state) {
            case AbyzState::IDLE:
                if (isInDetectionRange) {
                    abyz.state = AbyzState::CHASE;
                    updateChaseDirection(abyz, playerPosition, position);
                } else{
                    abyz.directionX = 0;
                    abyz.directionY = 0;
                }
                break;

            case AbyzState::CHASE:
                if (isInAttackRange) {
                    abyz.state = AbyzState::ATTACK;
                } else if (!isInDetectionRange) {
                    abyz.state = AbyzState::IDLE;
                } else {
                    updateChaseDirection(abyz, playerPosition, position);
                }
                break;

            case AbyzState::ATTACK:
                if (!isInAttackRange) {
                    abyz.state = AbyzState::CHASE;
                } else {
//                    attackPlayer(entity);
                }
                break;
        }

        auto xChange = abyz.directionX * abyz.speed * deltaTime;
        auto yChange = abyz.directionY * abyz.speed * deltaTime;

        positionComponent.shiftPosition(xChange, yChange);
    }
}

void AbyzControlSystem::updateChaseDirection(AbyzComponent& abyz, const Position& playerPosition, const Position& currentPosition) {
    float directionX = playerPosition.xPos - currentPosition.xPos;
    float directionY = playerPosition.yPos - currentPosition.yPos;
    float magnitude = std::sqrt(directionX * directionX + directionY * directionY);
    abyz.directionX = directionX / magnitude;
    abyz.directionY = directionY / magnitude;
}
