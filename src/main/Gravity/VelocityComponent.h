#ifndef VELOCITYCOMPONENT_H
#define VELOCITYCOMPONENT_H
#include "../PositionsAndMovement/Velocity.h"

struct VelocityComponent {
    Velocity velocity;
    explicit VelocityComponent(Velocity velocity): velocity(velocity) {}
};

#endif //VELOCITYCOMPONENT_H
