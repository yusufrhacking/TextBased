#ifndef HORIZONTALPLATFORMMOVEMENTCOMPONENT_H
#define HORIZONTALPLATFORMMOVEMENTCOMPONENT_H

struct HorizontalPlatformMovementComponent {
    float movementDistance = 10;
    unsigned int leftBound;
    unsigned int rightBound;
    int moveDirection = 1;
    HorizontalPlatformMovementComponent() = default;
    HorizontalPlatformMovementComponent(
        float movementDistance, unsigned int leftBound, unsigned int rightBound):
        movementDistance(movementDistance), leftBound(leftBound), rightBound(rightBound){}
};

#endif //HORIZONTALPLATFORMMOVEMENTCOMPONENT_H
