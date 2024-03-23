#ifndef TEXTBASED_CAMERAFOLLOWSYSTEM_H
#define TEXTBASED_CAMERAFOLLOWSYSTEM_H
#include "../MainPlayer/KeyboardMovementComponent.h"
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

    Position getNewCameraPositionByFrame(Position previousCameraPosition, const Position &playerPosition, const EntitySize &playerSizeOffset);

    Position getNewCameraPositionByCentering(Position previousCameraPosition, const Position &playerPosition, const EntitySize &playerSizeOffset);

    Position getNewCameraPositionByPlatformFollow(Position previousCameraPosition, const Position &playerPosition, const EntitySize &playerSizeOffset);

};


#endif //TEXTBASED_CAMERAFOLLOWSYSTEM_H
