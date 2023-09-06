#ifndef TEXTBASED_CAMERAFOLLOWSYSTEM_H
#define TEXTBASED_CAMERAFOLLOWSYSTEM_H
#include "../MainPlayer/MainPlayerComponent.h"
#include "../ECSObjects/UpdateSystem.h"
#include "../ECSObjects/System.h"
#include "Camera.h"


class CameraFollowSystem: public System {
public:
    explicit CameraFollowSystem();

    Camera updateCameraPosition(Position previousCameraPosition);
private:
    bool isAboveScreen(float relativePlayerYPos, float playerHeight) const;

    bool isBelowScreen(float relativePlayerYPos, float playerHeight);

    bool isRightOfScreen(float relativePlayerXPos, float playerWidth);

    bool isLeftOfScreen(float relativePlayerXPos, float playerWidth);

    Position getNewCameraPositionByFrame(Position previousCameraPosition, const Position &playerPosition, const Size &playerSizeOffset);

    Position getNewCameraPositionByCentering(Position previousCameraPosition, const Position &playerPosition, const Size &playerSizeOffset);
};


#endif //TEXTBASED_CAMERAFOLLOWSYSTEM_H
