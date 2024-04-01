#include "CoinBoxCollisionSystem.h"

#include "../HighLevel/ECSManager.h"
#include "../MainPlayer/DamageEvent.h"
#include "../MainPlayer/MainPlayerComponent.h"
#include "../Emma/CoinBoxComponent.h"

extern std::unique_ptr<ECSManager> ecsManager;
extern std::unique_ptr<EventBus> eventBus;

CoinBoxCollisionSystem::CoinBoxCollisionSystem() {
    listenToEvents();
}

void CoinBoxCollisionSystem::listenToEvents() {
    eventBus->listenToEvent<TopBottomCollisionEvent>(this, &CoinBoxCollisionSystem::onTopBottomCollision);
}

void CoinBoxCollisionSystem::onTopBottomCollision(TopBottomCollisionEvent &event) {
    if (ecsManager->hasComponent<CoinBoxComponent>(event.top)) {
        if(ecsManager->hasComponent<MainPlayerComponent>(event.bottom)) {
            spdlog::info("COIN BOX COLLISION!");
        }
    }
}