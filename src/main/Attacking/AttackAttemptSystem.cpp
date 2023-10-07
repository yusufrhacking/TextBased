#include "AttackAttemptSystem.h"
#include "../HighLevel/ECSManager.h"
#include "../EventSystem/EventBus.h"
#include "ActiveWeaponComponent.h"
#include "AttackType.h"
#include "AttackableComponent.h"
#include "AttemptedAttackEvent.h"
#include "SuccessfulAttackEvent.h"
#include "../PositionsAndMovement/PositionComponent.h"
#include "../PositionsAndMovement/DistanceCalculator.h"
#include "../MainPlayer/TiedChildComponent.h"
#include "../Woodworking/AxeComponent.h"

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

void AttackAttemptSystem::onAttackAttempt(AttemptedAttackEvent &event) {
    const auto &attackerSurface = ecsManager->getComponentFromEntity<TextComponent>(event.attacker).getSurfaceSize();
    const auto &attackerPosition = ecsManager->getComponentFromEntity<PositionComponent>(event.attacker).getPosition();

    for (auto entity: getRelevantEntities()) {
        if (entity == event.attacker) {
            return;
        }
        const auto &surface = ecsManager->getComponentFromEntity<TextComponent>(entity).getSurfaceSize();
        const auto &position = ecsManager->getComponentFromEntity<PositionComponent>(entity).getPosition();

        if (ecsManager->hasComponent<ActiveWeaponComponent>(event.attacker)) {
            if (DistanceCalculator::isInAllowedRange(attackerPosition, position, attackerSurface, surface,
                                                     ATTACK_RANGE)) {
                Item attackingItem = ecsManager->getComponentFromEntity<ActiveWeaponComponent>(event.attacker).item;
                eventBus->emitEvent<SuccessfulAttackEvent>(event.attacker, entity, Attacking::getAttackTypeFromItem(attackingItem));
                return;
            }
        }

    }
}
