#ifndef TOPBOTTOMCOLLISIONEVENT_H
#define TOPBOTTOMCOLLISIONEVENT_H
#include "../ECSObjects/Entity.h"
#include "../EventSystem/Event.h"

struct TopBottomCollisionEvent: Event {
    Entity top;
    Entity bottom;
    TopBottomCollisionEvent(Entity top, Entity bottom): top(top), bottom(bottom) {}
};

#endif //TOPBOTTOMCOLLISIONEVENT_H
