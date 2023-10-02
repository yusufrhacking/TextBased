#include "AttackAttemptSystem.h"
#include "../HighLevel/ECSManager.h"
#include "../EventSystem/EventBus.h"
#include "AttemptedAttackEvent.h"

extern std::unique_ptr<ECSManager> ecsManager;
extern std::unique_ptr<EventBus> eventBus;

AttackAttemptSystem::AttackAttemptSystem() {

}

void AttackAttemptSystem::listenToEvents() {
    eventBus->listenToEvent<AttemptedAttackEvent>(this, &AttackAttemptSystem::onAttackAttempt);
}

void AttackAttemptSystem::onAttackAttempt(AttemptedAttackEvent& event) {

}
