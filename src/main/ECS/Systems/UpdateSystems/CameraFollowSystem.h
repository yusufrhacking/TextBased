#ifndef TEXTBASED_CAMERAFOLLOWSYSTEM_H
#define TEXTBASED_CAMERAFOLLOWSYSTEM_H


#include "../../Components/MainPlayerComponent.h"
#include "../../Components/PositionComponent.h"
#include "UpdateSystem.h"

class CameraFollowSystem: public UpdateSystem {
public:
    explicit CameraFollowSystem();

    void update(double deltaTime) override;
};


#endif //TEXTBASED_CAMERAFOLLOWSYSTEM_H
