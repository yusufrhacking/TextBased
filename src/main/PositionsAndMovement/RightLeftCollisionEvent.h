#ifndef RIGHTLEFTCOLLISIONEVENT_H
#define RIGHTLEFTCOLLISIONEVENT_H

#include "../ECSObjects/Entity.h"
#include "../EventSystem/Event.h"

struct RightLeftCollisionEvent: Event {
    Entity right;
    Entity left;
    RightLeftCollisionEvent(Entity right, Entity left): right(right), left(left) {}
};

#endif //RIGHTLEFTCOLLISIONEVENT_H
