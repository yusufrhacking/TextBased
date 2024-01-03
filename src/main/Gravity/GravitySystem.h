#ifndef GRAVITYSYSTEM_H
#define GRAVITYSYSTEM_H
#include "../ECSObjects/UpdateSystem.h"


class GravitySystem: public UpdateSystem {
    float velocityForce = 1.0;
    float terminalVelocity = 40.0;
public:
    GravitySystem();
    void update(double deltaTime) override;
};



#endif //GRAVITYSYSTEM_H
