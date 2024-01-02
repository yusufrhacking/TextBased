#ifndef ABYZTARGETINGCOMPONENT_H
#define ABYZTARGETINGCOMPONENT_H
#include "../ECSObjects/Entity.h"
#include "../PositionsAndMovement/Position.h"

struct AbyzTargetingComponent {
    Entity target;

    AbyzTargetingComponent() = default;

    explicit AbyzTargetingComponent(Entity target): target(target) {}
};

#endif
