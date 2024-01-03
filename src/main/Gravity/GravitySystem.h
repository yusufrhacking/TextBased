#ifndef GRAVITYSYSTEM_H
#define GRAVITYSYSTEM_H
#include "../ECSObjects/UpdateSystem.h"


class GravitySystem: public UpdateSystem {
    float velocityForce = 125.0;
    float terminalVelocity = 500.0;
public:
    GravitySystem();
    void update(double deltaTime) override;
};



#endif //GRAVITYSYSTEM_H
