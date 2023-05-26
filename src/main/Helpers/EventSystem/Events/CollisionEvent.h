#ifndef TEXTBASED_COLLISIONEVENT_H
#define TEXTBASED_COLLISIONEVENT_H

#include "Event.h"
#include "../../../ECS/Design/Objects/Entity.h"

class CollisionEvent: public Event{
public:
    Entity offender;
    Entity defender;
    double deltaTime;
    CollisionEvent(Entity offender, Entity defender, double deltaTime):
    offender(offender), defender(defender), deltaTime(deltaTime) {}
};

#endif //TEXTBASED_COLLISIONEVENT_H
