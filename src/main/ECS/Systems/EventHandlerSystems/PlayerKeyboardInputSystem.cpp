#include "PlayerKeyboardInputSystem.h"
#include "../../../Helpers/EventSystem/Events/KeyEvent.h"
#include "../UpdateSystems/AutonomousMovementSystem.h"
#include "../SpecialSystems//UnprocessedMovements/UnprocessedKeyboardMovementSystem.h"

extern std::unique_ptr<ECSManager> ecsManager;
extern std::unique_ptr<EventBus> eventBus;


PlayerKeyboardInputSystem::PlayerKeyboardInputSystem() {
    requireComponent<PositionComponent>();
    requireComponent<TextComponent>();
    requireComponent<MainPlayerComponent>();
    eventBus->listenToEvent<KeyEvent>(this, &PlayerKeyboardInputSystem::onKeyPressed);
}

void PlayerKeyboardInputSystem::onKeyPressed(KeyEvent& event) {
    for (auto entity: getRelevantEntities()){
        auto& positionComponent = ecsManager->getComponentFromEntity<PositionComponent>(entity);
        auto playerVelocity = ecsManager->getComponentFromEntity<MainPlayerComponent>(entity).movementSpeed;
        double xChange = 0;
        double yChange = 0;

        switch (event.character){
            case 'w':
                yChange += -1*playerVelocity->yVelocity; break;
            case 'a':
                xChange += -1*playerVelocity->xVelocity; break;
            case 's':
                yChange += playerVelocity->yVelocity; break;
            case 'd':
                xChange += playerVelocity->xVelocity; break;
        }

        UnprocessedMovement movement = UnprocessedMovement(entity, xChange, yChange);

        ecsManager->getSystem<UnprocessedKeyboardMovementSystem>().queueMovement(movement);

    }
}


