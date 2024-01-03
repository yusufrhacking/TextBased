#include "PlayerKeyboardInputSystem.h"
#include "UnprocessedMovementSystem.h"
#include "../PositionsAndMovement/PositionComponent.h"
#include "../PositionsAndMovement/LiveComponent.h"

extern std::unique_ptr<ECSManager> ecsManager;
extern std::unique_ptr<EventBus> eventBus;


PlayerKeyboardInputSystem::PlayerKeyboardInputSystem() {
    requireComponent<PositionComponent>();
    requireComponent<TextComponent>();
    requireComponent<KeyboardMovementComponent>();
    requireComponent<LiveComponent>();
    eventBus->listenToEvent<GameKeyEvent>(this, &PlayerKeyboardInputSystem::onKeyPressed);
}

void PlayerKeyboardInputSystem::onKeyPressed(GameKeyEvent& event) {
    for (auto entity: getRelevantEntities()){
        auto& positionComponent = ecsManager->getComponentFromEntity<PositionComponent>(entity);
        auto playerVelocity = ecsManager->getComponentFromEntity<KeyboardMovementComponent>(entity).movementSpeed;
        double xChange = 0;
        double yChange = 0;

        switch (event.getKey()){
            case GameKey::MOVE_UP:
                yChange += -1*playerVelocity->y; break;
            case GameKey::MOVE_LEFT:
                xChange += -1*playerVelocity->x; break;
            case GameKey::MOVE_DOWN:
                yChange += playerVelocity->y; break;
            case GameKey::MOVE_RIGHT:
                xChange += playerVelocity->x; break;
            default:
                break;
        }

        UnprocessedMovement movement = UnprocessedMovement(entity, xChange, yChange);

        ecsManager->getSystem<UnprocessedMovementSystem>().queueMovement(movement);

    }
}


