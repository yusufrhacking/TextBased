#ifndef LIFEGATECOMPONENT_H
#define LIFEGATECOMPONENT_H

struct LifeGateComponent {
    float mustBeAboveYPos;
    LifeGateComponent() = default;
    LifeGateComponent(float yPos): mustBeAboveYPos(yPos) {}
};

#endif //LIFEGATECOMPONENT_H
