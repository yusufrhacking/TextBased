#ifndef TEXTBASED_MOVEMENTEVENT_H
#define TEXTBASED_MOVEMENTEVENT_H

#include "Event.h"
#include "../../Objects/Velocity.h"
#include "../../../ECS/Design/Objects/Entity.h"

class MovementEvent: public Event{
public:
    Entity entity;
    Velocity change;
    explicit MovementEvent(Entity entity, Velocity change){
        this->entity = entity;
        this->change = change;
    }
};

#endif //TEXTBASED_MOVEMENTEVENT_H
