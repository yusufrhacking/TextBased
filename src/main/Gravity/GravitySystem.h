#ifndef GRAVITYSYSTEM_H
#define GRAVITYSYSTEM_H
#include "../ECSObjects/UpdateSystem.h"


class GravitySystem: public UpdateSystem {
    float gravityForce = 300.0;
    float terminalVelocity = 750.0;
public:
    GravitySystem();
    void update(double deltaTime) override;
};



#endif //GRAVITYSYSTEM_H
