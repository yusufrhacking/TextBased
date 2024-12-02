#ifndef HORIZONTALPLATFORMMOVEMENTSYSTEM_H
#define HORIZONTALPLATFORMMOVEMENTSYSTEM_H
#include "../ECSObjects/UpdateSystem.h"


class HorizontalPlatformMovementSystem: public UpdateSystem {
public:
    HorizontalPlatformMovementSystem();
    void update(double deltaTime) override;

};



#endif //HORIZONTALPLATFORMMOVEMENTSYSTEM_H
