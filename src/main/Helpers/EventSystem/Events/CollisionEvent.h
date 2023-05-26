#ifndef TEXTBASED_COLLISIONEVENT_H
#define TEXTBASED_COLLISIONEVENT_H

#include "Event.h"
#include "../../../ECS/Design/Objects/Entity.h"

class CollisionEvent: public Event{
public:
    Entity a;
    Entity b;
    double deltaTime;
    CollisionEvent(Entity a, Entity b, double deltaTime):
            a(a), b(b), deltaTime(deltaTime) {}
};

#endif //TEXTBASED_COLLISIONEVENT_H
