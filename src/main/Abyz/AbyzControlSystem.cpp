#include "AbyzControlSystem.h"
#include "AbyzComponent.h"
#include "../PositionsAndMovement/PositionComponent.h"
#include "../HighLevel/ECSManager.h"
#include "../MainPlayer/MainPlayerAccessSystem.h"
#include "../PositionsAndMovement/DistanceCalculator.h"
#include "../Attacking/SuccessfulAttackEvent.h"
#include "../Health/HealthComponent.h"

extern std::unique_ptr<ECSManager> ecsManager;
extern std::unique_ptr<EventBus> eventBus;

const float ATTACK_RADIUS = 10;
const float DETECTION_MULTIPLIER = 50;
const float DETECTION_RADIUS = ATTACK_RADIUS * DETECTION_MULTIPLIER;
const float ATTACK_COOLDOWN = 5.0f;
const float RESUME_CHASE_AFTER_ATTACK = 2.0f;

AbyzControlSystem::AbyzControlSystem() {
    requireComponent<AbyzComponent>();
    requireComponent<PositionComponent>();
    requireComponent<TextComponent>();
}

void AbyzControlSystem::update(double deltaTime) {
    Entity mainPlayer = ecsManager->getSystem<MainPlayerAccessSystem>().getMainPlayer();
    Position playerPosition = ecsManager->getComponentFromEntity<PositionComponent>(mainPlayer).getPosition();
    Size playerSize = ecsManager->getComponentFromEntity<TextComponent>(mainPlayer).getSurfaceSize();

    for (Entity entity : getRelevantEntities()) {
        auto& positionComponent = ecsManager->getComponentFromEntity<PositionComponent>(entity);
        auto position = positionComponent.getPosition();
        auto size = ecsManager->getComponentFromEntity<TextComponent>(entity).getSurfaceSize();
        auto& abyz = ecsManager->getComponentFromEntity<AbyzComponent>(entity);

        auto& healthComponent = ecsManager->getComponentFromEntity<HealthComponent>(entity);
        float healthQuarter = healthComponent.initialHealth / 4.0f;
        int quartersLeft = 4 - static_cast<int>(static_cast<float>(healthComponent.initialHealth - healthComponent.health) / healthQuarter);
        ecsManager->getComponentFromEntity<TextComponent>(entity).text = ecsManager->getComponentFromEntity<TextComponent>(entity).text.substr(0, quartersLeft);

        bool isInDetectionRange = DistanceCalculator::isInAllowedRange(playerPosition, position, playerSize, size, DETECTION_RADIUS);
        bool isInAttackRange = DistanceCalculator::isInAllowedRange(playerPosition, position, playerSize, size, ATTACK_RADIUS);

        abyz.attackCooldownRemaining -= (float)deltaTime;
        if (abyz.attackCooldownRemaining < 0) {
            abyz.attackCooldownRemaining = 0;
        }

        switch (abyz.state) {
            case AbyzState::IDLE:
                if (isInDetectionRange) {
                    chase(abyz, playerPosition, position);
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
                    chase(abyz, playerPosition, position);
                }
                break;

            case AbyzState::ATTACK:
                if (!isInAttackRange || abyz.attackCooldownRemaining > 0) {
                    chase(abyz, playerPosition, position);
                } else {
                    tryToAttackPlayer(abyz, entity, mainPlayer);
                }
                break;

            case AbyzState::COOLDOWN:
                if (abyz.attackCooldownRemaining < RESUME_CHASE_AFTER_ATTACK){
                    abyz.state = AbyzState::IDLE;
                }
                break;
        }

        auto xChange = abyz.directionX * abyz.speed * deltaTime;
        auto yChange = abyz.directionY * abyz.speed * deltaTime;

        positionComponent.shiftPosition(xChange, yChange);
    }
}

void AbyzControlSystem::chase(AbyzComponent& abyz, const Position& playerPosition, const Position& currentPosition) {
    abyz.state = AbyzState::CHASE;
    float directionX = playerPosition.xPos - currentPosition.xPos;
    float directionY = playerPosition.yPos - currentPosition.yPos;
    float magnitude = std::sqrt(directionX * directionX + directionY * directionY);
    abyz.directionX = directionX / magnitude;
    abyz.directionY = directionY / magnitude;
}

void AbyzControlSystem::tryToAttackPlayer(AbyzComponent& abyz, Entity abyzEntity, Entity mainPlayer) {
    if (abyz.attackCooldownRemaining <= 0) {
        abyz.attackCooldownRemaining = ATTACK_COOLDOWN;
        abyz.state = AbyzState::COOLDOWN;
        eventBus->emitEvent<SuccessfulAttackEvent>(abyzEntity, mainPlayer, AttackType::ABYZ);
    }
}

