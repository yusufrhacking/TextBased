#ifndef HORIZONTALPLATFORMMOVEMENTCOMPONENT_H
#define HORIZONTALPLATFORMMOVEMENTCOMPONENT_H

struct HorizontalPlatformMovementComponent {
    unsigned int leftBound;
    unsigned int rightBound;
    int moveDirection = 1;
    HorizontalPlatformMovementComponent() = default;
    HorizontalPlatformMovementComponent(unsigned int leftBound, unsigned int rightBound): leftBound(leftBound), rightBound(rightBound){}
};

#endif //HORIZONTALPLATFORMMOVEMENTCOMPONENT_H
