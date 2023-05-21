#ifndef TEXTBASED_CAMERAFOLLOWSYSTEM_H
#define TEXTBASED_CAMERAFOLLOWSYSTEM_H


#include "../../Components/MainPlayerComponent.h"
#include "../../Components/PositionComponent.h"
#include "UpdateSystem.h"

class CameraFollowSystem: public UpdateSystem {
    CameraFollowSystem(){
        requireComponent<MainPlayerComponent>();
        requireComponent<PositionComponent>();
    }

    void update(double deltaTime) override;
};


#endif //TEXTBASED_CAMERAFOLLOWSYSTEM_H
