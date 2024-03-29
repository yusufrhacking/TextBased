#include "PlayerKeyboardInputSystem.h"
#include "UnprocessedKeyboardMovementSystem.h"
#include "../PositionsAndMovement/PositionComponent.h"
#include "../PositionsAndMovement/LiveComponent.h"

extern std::unique_ptr<ECSManager> ecsManager;
extern std::unique_ptr<EventBus> eventBus;


PlayerKeyboardInputSystem::PlayerKeyboardInputSystem() {
    requireComponent<PositionComponent>();
    requireComponent<TextComponent>();
    requireComponent<MainPlayerComponent>();
    requireComponent<LiveComponent>();
    eventBus->listenToEvent<GameKeyEvent>(this, &PlayerKeyboardInputSystem::onKeyPressed);
}

void PlayerKeyboardInputSystem::onKeyPressed(GameKeyEvent& event) {
    for (auto entity: getRelevantEntities()){
        auto& positionComponent = ecsManager->getComponentFromEntity<PositionComponent>(entity);
        auto playerVelocity = ecsManager->getComponentFromEntity<MainPlayerComponent>(entity).movementSpeed;
        double xChange = 0;
        double yChange = 0;

        switch (event.getKey()){
            case GameKey::MOVE_UP:
                yChange += -1*playerVelocity->yVelocity; break;
            case GameKey::MOVE_LEFT:
                xChange += -1*playerVelocity->xVelocity; break;
            case GameKey::MOVE_DOWN:
                yChange += playerVelocity->yVelocity; break;
            case GameKey::MOVE_RIGHT:
                xChange += playerVelocity->xVelocity; break;
            default:
                break;
        }

        UnprocessedMovement movement = UnprocessedMovement(entity, xChange, yChange);

        ecsManager->getSystem<UnprocessedKeyboardMovementSystem>().queueMovement(movement);

    }
}


