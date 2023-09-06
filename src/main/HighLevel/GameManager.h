#ifndef TEXTBASED_GAMEMANAGER_H
#define TEXTBASED_GAMEMANAGER_H
#include <memory>
#include "ECSManager.h"
#include "../PositionsAndMovement/CollisionHandleSystem.h"
#include "../MainPlayer/PlayerKeyboardInputSystem.h"
#include "../Camera/CameraFollowSystem.h"
#include "../MainPlayer/UnprocessedKeyboardMovementSystem.h"
#include "../TheCanon/CanonRegisteringSystem.h"
#include "../MainPlayer/MovementHandleSystem.h"
#include "../TheCanon/CanonMovementHandleSystem.h"
#include "../TextInput/WordComprehensionSystem.h"

class GameManager {
private:
    void setupSystems();
    Canon canon;
    Position startingPosition;
public:
    explicit GameManager(Position position);
    void setup();
    void update(double deltaTime);

};


#endif //TEXTBASED_GAMEMANAGER_H
