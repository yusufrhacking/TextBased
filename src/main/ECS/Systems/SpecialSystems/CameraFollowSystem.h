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

    bool isOutsideTopOfScreen(float relativePlayerYPos, float playerHeight) const;

    bool isOutsideBottomOfScreen(float relativePlayerYPos, float playerHeight);
};


#endif //TEXTBASED_CAMERAFOLLOWSYSTEM_H
