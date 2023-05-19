#include "PlayerMovementSystem.h"
#include "../../../Helpers/EventSystem/Events/KeyEvent.h"
#include "../EventHandlerSystems/AutonomousMovementSystem.h"

extern std::unique_ptr<ECSManager> ecsManager;
extern std::unique_ptr<EventBus> eventBus;

PlayerMovementSystem::PlayerMovementSystem() {
    requireComponent<PositionComponent>();
    requireComponent<TextComponent>();
    requireComponent<PlayerMovementComponent>();
    eventBus->listenToEvent<KeyEvent>(this, &PlayerMovementSystem::onKeyPressed);
}

void PlayerMovementSystem::onKeyPressed(KeyEvent& event) {
    for (auto entity: getRelevantEntities()){
        auto position = ecsManager->getComponentFromEntity<PositionComponent>(entity).position;
        auto playerVelocity = ecsManager->getComponentFromEntity<PlayerMovementComponent>(entity).velocity;
        auto xChange = playerVelocity->xVelocity;
        auto yChange = playerVelocity->yVelocity;

        switch (event.keyType){
            case W_KEY:
                position->yPos -= (float)yChange; break;
            case A_KEY:
                position->xPos -= (float)xChange; break;
            case S_KEY:
                position->yPos += (float)yChange; break;
            case D_KEY:
                position->xPos += (float)xChange; break;
        }
    }
}


