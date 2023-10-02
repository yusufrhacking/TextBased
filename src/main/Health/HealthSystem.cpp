#include <spdlog/spdlog.h>
#include "HealthSystem.h"
#include "../HighLevel/ECSManager.h"
#include "../Attacking/SuccessfulAttackEvent.h"
#include "HealthComponent.h"

extern std::unique_ptr<ECSManager> ecsManager;
extern std::unique_ptr<EventBus> eventBus;

HealthSystem::HealthSystem() {
    listenToEvents();
}

void HealthSystem::listenToEvents() {
    eventBus->listenToEvent<SuccessfulAttackEvent>(this, &HealthSystem::onAttack);
}

void HealthSystem::onAttack(SuccessfulAttackEvent& event) {
    Entity victim = event.victim;
    if (ecsManager->hasComponent<HealthComponent>(victim)){
        auto& healthComponent = ecsManager->getComponentFromEntity<HealthComponent>(victim);
        auto damage = Attacking::getDamageFromAttackType(event.attackType);
        healthComponent.health -= damage;
        spdlog::debug("Lowered entity {}'s health by {}", victim.getId(), damage);
    }
}
