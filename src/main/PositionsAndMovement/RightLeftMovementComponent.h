#ifndef RIGHTLEFTMOVEMENTCOMPONENT_H
#define RIGHTLEFTMOVEMENTCOMPONENT_H

struct RightLeftMovementComponent {
    float movementDistance;
    RightLeftMovementComponent() = default;
    explicit RightLeftMovementComponent(float movementDistance): movementDistance(movementDistance) {}
};

#endif //RIGHTLEFTMOVEMENTCOMPONENT_H
