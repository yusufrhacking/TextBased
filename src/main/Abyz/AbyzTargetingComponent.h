#ifndef ABYZTARGETINGCOMPONENT_H
#define ABYZTARGETINGCOMPONENT_H
#include "../ECSObjects/Entity.h"
#include "../PositionsAndMovement/Position.h"

struct AbyzTargetingComponent {
    Entity target;
    Position targetPosition;

    AbyzTargetingComponent() = default;

    AbyzTargetingComponent(Entity target, Position targetPosition): target(target), targetPosition(targetPosition) {}
};

#endif
