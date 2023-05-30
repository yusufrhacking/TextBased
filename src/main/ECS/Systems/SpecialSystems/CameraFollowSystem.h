#ifndef TEXTBASED_CAMERAFOLLOWSYSTEM_H
#define TEXTBASED_CAMERAFOLLOWSYSTEM_H


#include "../../Components/MainPlayerComponent.h"
#include "../../Components/PositionComponent.h"
#include "../UpdateSystems/UpdateSystem.h"


class CameraFollowSystem: public System {
public:
    explicit CameraFollowSystem();

    void update();
private:
    bool isAboveScreen(float relativePlayerYPos, float playerHeight) const;

    bool isBelowScreen(float relativePlayerYPos, float playerHeight);

    bool isRightOfScreen(float relativePlayerXPos, float playerWidth);

    bool isLeftOfScreen(float relativePlayerXPos, float playerWidth);
};


#endif //TEXTBASED_CAMERAFOLLOWSYSTEM_H
