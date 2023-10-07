#include "AttackAttemptSystem.h"
#include "../HighLevel/ECSManager.h"
#include "../EventSystem/EventBus.h"
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

void AttackAttemptSystem::onAttackAttempt(AttemptedAttackEvent& event) {
    const auto& attackerSurface = ecsManager->getComponentFromEntity<TextComponent>(event.attacker).getSurfaceSize();
    const auto& attackerPosition = ecsManager->getComponentFromEntity<PositionComponent>(event.attacker).getPosition();

    for (auto entity: getRelevantEntities()){
        if (entity == event.attacker){
            return;
        }
        const auto& surface = ecsManager->getComponentFromEntity<TextComponent>(entity).getSurfaceSize();
        const auto& position = ecsManager->getComponentFromEntity<PositionComponent>(entity).getPosition();

        if (ecsManager->hasComponent<TiedChildComponent>(event.attacker)){
            for (auto childEntity: ecsManager->getComponentFromEntity<TiedChildComponent>(event.attacker).entities){
                if (ecsManager->hasComponent<AxeComponent>(childEntity)){

                    if (DistanceCalculator::isInAllowedRange(attackerPosition, position, attackerSurface, surface, ATTACK_RANGE)){
                        eventBus->emitEvent<SuccessfulAttackEvent>(event.attacker, entity, AttackType::BASIC);
                        return;
                    }
                }
            }

        }

    }
}
