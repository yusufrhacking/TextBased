#ifndef TEXTBASED_READYTOMOVEEVENT_H
#define TEXTBASED_READYTOMOVEEVENT_H

#include "Event.h"
#include "../../Objects/Velocity.h"
#include "../../../ECS/Design/Objects/Entity.h"

class ReadyToMoveEvent: public Event{
public:
    Entity entity;
    Velocity change;
    explicit ReadyToMoveEvent(Entity entity, Velocity change){
        this->entity = entity;
        this->change = change;
    }
};

#endif //TEXTBASED_READYTOMOVEEVENT_H
