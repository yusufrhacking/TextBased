#ifndef JOURNEYCOMPONENT_H
#define JOURNEYCOMPONENT_H
#include "../PositionsAndMovement/Velocity.h"

struct JourneyComponent {
    Velocity velocity;
    double goalXChange;
    double goalYChange;
    double totalXTraveled = 0;
    double totalYTraveled = 0;

    JourneyComponent() = default;

    JourneyComponent(Velocity velocity, double goalXChange, double goalYChange):
    velocity(velocity), goalXChange(goalXChange), goalYChange(goalYChange) {}
};

#endif //JOURNEYCOMPONENT_H
