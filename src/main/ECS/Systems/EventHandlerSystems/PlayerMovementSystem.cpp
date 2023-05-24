#include "PlayerMovementSystem.h"
#include "../../../Helpers/EventSystem/Events/KeyEvent.h"
#include "../UpdateSystems/AutonomousMovementSystem.h"

extern std::unique_ptr<ECSManager> ecsManager;
extern std::unique_ptr<EventBus> eventBus;

PlayerMovementSystem::PlayerMovementSystem() {
    requireComponent<PositionComponent>();
    requireComponent<TextComponent>();
    requireComponent<MainPlayerComponent>();
    eventBus->listenToEvent<KeyEvent>(this, &PlayerMovementSystem::onKeyPressed);
}

void PlayerMovementSystem::onKeyPressed(KeyEvent& event) {
    for (auto entity: getRelevantEntities()){
        auto& positionComponent = ecsManager->getComponentFromEntity<PositionComponent>(entity);
        auto playerVelocity = ecsManager->getComponentFromEntity<MainPlayerComponent>(entity).movementSpeed;
        int xChange = 0;
        int yChange = 0;

        switch (event.keyType){
            case W_KEY:
                yChange = -1*playerVelocity->yVelocity; break;
            case A_KEY:
                xChange = -1*playerVelocity->xVelocity; break;
            case S_KEY:
                yChange = playerVelocity->yVelocity; break;
            case D_KEY:
                xChange = playerVelocity->xVelocity; break;
        }

        positionComponent.changePosition(xChange, yChange);

    }
}


