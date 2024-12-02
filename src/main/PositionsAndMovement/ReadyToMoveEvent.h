#ifndef TEXTBASED_READYTOMOVEEVENT_H
#define TEXTBASED_READYTOMOVEEVENT_H
#include "../EventSystem/Event.h"
#include "Velocity.h"

class ReadyToMoveEvent: public Event{
public:
    Entity entity;
    Velocity change;
    explicit ReadyToMoveEvent(Entity entity, Velocity change){
        this->entity = entity;
        this->change = change;
    }

    explicit ReadyToMoveEvent(Entity entity, float xChange, float yChange){
        this->entity = entity;
        this->change = Velocity(xChange, yChange);
    }
};

#endif //TEXTBASED_READYTOMOVEEVENT_H
