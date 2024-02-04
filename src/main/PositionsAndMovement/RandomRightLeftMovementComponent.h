#ifndef RANDOMRIGHTLEFTMOVEMENTCOMPONENT_H
#define RANDOMRIGHTLEFTMOVEMENTCOMPONENT_H

struct RandomRightLeftMovementComponent {
    float movementDistance{};
    int moveDirection{};
    std::chrono::steady_clock::time_point lastSwap{};
    RandomRightLeftMovementComponent() = default;
    explicit RandomRightLeftMovementComponent(float movementDistance): movementDistance(movementDistance) {}
};

#endif
