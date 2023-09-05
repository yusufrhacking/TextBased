#ifndef TEXTBASED_READYTOMOVEEVENT_H
#define TEXTBASED_READYTOMOVEEVENT_H

#include "../EventSystem/Event.h"
#include "Velocity.h"
#include "../ECS/Design/Objects/Entity.h"

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
