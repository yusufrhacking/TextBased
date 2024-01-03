#include "JumpingSystem.h"

#include "JumpingComponent.h"
#include "../TextInput/GameKeyEvent.h"
#include "../PositionsAndMovement/PositionComponent.h"
#include "../PositionsAndMovement/LiveComponent.h"
#include "../HighLevel/ECSManager.h"
#include "../PositionsAndMovement/VelocityComponent.h"

extern std::unique_ptr<ECSManager> ecsManager;
extern std::unique_ptr<EventBus> eventBus;

JumpingSystem::JumpingSystem() {
    requireComponent<VelocityComponent>();
    requireComponent<JumpingComponent>();
    requireComponent<LiveComponent>();
    eventBus->listenToEvent<GameKeyEvent>(this, &JumpingSystem::onKeyPressed);
}

void JumpingSystem::onKeyPressed(GameKeyEvent& event) {
    for (auto entity: getRelevantEntities()) {
        auto& playerVelocity = ecsManager->getComponentFromEntity<VelocityComponent>(entity).velocity;

        switch (event.getKey()) {
            case GameKey::MOVE_UP:
                playerVelocity.y -= 300;
            default:
                break;
        }
    }
}

