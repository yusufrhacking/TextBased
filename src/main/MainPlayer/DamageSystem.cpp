#include "DamageSystem.h"

#include "../HighLevel/ECSManager.h"
#include "../MainPlayer/MainPlayerComponent.h"
#include "../Platformer/PlatformComponent.h"
#include "../PositionsAndMovement/RightLeftCollisionEvent.h"


extern std::unique_ptr<ECSManager> ecsManager;
extern std::unique_ptr<EventBus> eventBus;

DamageSystem::DamageSystem() {
    listenToEvents();
}

void DamageSystem::listenToEvents() {
    eventBus->listenToEvent<DamageEvent>(this, &DamageSystem::onDamage);
}

void DamageSystem::onDamage(DamageEvent& event) {
    if (ecsManager->hasComponent<TextComponent>(event.damagedEntity)) {
        ecsManager->getComponentFromEntity<TextComponent>(event.damagedEntity).text.pop_back();
    }
}
