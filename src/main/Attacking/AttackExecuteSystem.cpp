#include "AttackExecuteSystem.h"
#include "../HighLevel/ECSManager.h"
#include "SuccessfulAttackEvent.h"

extern std::unique_ptr<ECSManager> ecsManager;
extern std::unique_ptr<EventBus> eventBus;

AttackExecuteSystem::AttackExecuteSystem() {
    listenToEvents();
}

void AttackExecuteSystem::listenToEvents() {
    eventBus->listenToEvent<SuccessfulAttackEvent>(this, &AttackExecuteSystem::onAttack);
}

void AttackExecuteSystem::onAttack(SuccessfulAttackEvent& event) {

}
