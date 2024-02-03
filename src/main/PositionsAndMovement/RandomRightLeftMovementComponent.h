#ifndef RANDOMRIGHTLEFTMOVEMENTSYSTEM_H
#define RANDOMRIGHTLEFTMOVEMENTSYSTEM_H

struct RandomRightLeftMovementComponent {
    float movementDistance;
    RandomRightLeftMovementComponent() = default;
    explicit RandomRightLeftMovementComponent(float movementDistance): movementDistance(movementDistance) {}
};

#endif //RANDOMRIGHTLEFTMOVEMENTSYSTEM_H
