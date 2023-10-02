#include "AttackAttemptSystem.h"
#include "../HighLevel/ECSManager.h"
#include "../EventSystem/EventBus.h"
#include "AttackableComponent.h"
#include "AttemptedAttackEvent.h"
#include "SuccessfulAttackEvent.h"
#include "../PositionsAndMovement/PositionComponent.h"
#include "../PositionsAndMovement/DistanceCalculator.h"

extern std::unique_ptr<ECSManager> ecsManager;
extern std::unique_ptr<EventBus> eventBus;

AttackAttemptSystem::AttackAttemptSystem() {
    requireComponent<AttackableComponent>();
    requireComponent<PositionComponent>();
    requireComponent<TextComponent>();
    listenToEvents();
}

void AttackAttemptSystem::listenToEvents() {
    eventBus->listenToEvent<AttemptedAttackEvent>(this, &AttackAttemptSystem::onAttackAttempt);
}

void AttackAttemptSystem::onAttackAttempt(AttemptedAttackEvent& event) {
    const auto& attackerSurface = ecsManager->getComponentFromEntity<TextComponent>(event.attacker).getSurfaceSize();
    const auto& attackerPosition = ecsManager->getComponentFromEntity<PositionComponent>(event.attacker).getPosition();


    for (auto entity: getRelevantEntities()){
        const auto& surface = ecsManager->getComponentFromEntity<TextComponent>(entity).getSurfaceSize();
        const auto& position = ecsManager->getComponentFromEntity<PositionComponent>(entity).getPosition();
        if (DistanceCalculator::isInAllowedRange(attackerPosition, position, attackerSurface, surface, ATTACK_RANGE)){
            eventBus->emitEvent<SuccessfulAttackEvent>();
            return;
        }
    }
}
