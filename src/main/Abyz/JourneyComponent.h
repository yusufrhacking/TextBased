#ifndef JOURNEYCOMPONENT_H
#define JOURNEYCOMPONENT_H
#include "../PositionsAndMovement/Velocity.h"

struct JourneyComponent {
    Velocity velocity;
    float xChange;
    float yChange;

    JourneyComponent(Velocity velocity, float xChange, float yChange):
    velocity(velocity), xChange(xChange), yChange(yChange) {}
};

#endif //JOURNEYCOMPONENT_H
