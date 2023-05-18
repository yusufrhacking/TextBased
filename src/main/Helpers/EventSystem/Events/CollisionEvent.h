#ifndef TEXTBASED_COLLISIONEVENT_H
#define TEXTBASED_COLLISIONEVENT_H

#include "Event.h"
#include "../../../ECS/Design/Objects/Entity.h"

class CollisionEvent: public Event{
public:
    Entity a;
    Entity b;
    CollisionEvent(Entity a, Entity b): a(a), b(b) {}
};

#endif //TEXTBASED_COLLISIONEVENT_H
