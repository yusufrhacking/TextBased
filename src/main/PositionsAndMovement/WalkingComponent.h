#ifndef RIGHTLEFTMOVEMENTCOMPONENT_H
#define RIGHTLEFTMOVEMENTCOMPONENT_H

struct WalkingComponent {
    float movementDistance;
    WalkingComponent() = default;
    explicit WalkingComponent(float movementDistance): movementDistance(movementDistance) {}
};

#endif //RIGHTLEFTMOVEMENTCOMPONENT_H
