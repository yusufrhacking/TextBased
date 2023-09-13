#ifndef TEXTBASED_PLAYERPICKUPEVENT_H
#define TEXTBASED_PLAYERPICKUPEVENT_H
#include "../ECSObjects/Entity.h"
#include "../EventSystem/Event.h"

struct PlayerPickUpEvent: public Event{
    Entity picker;
    explicit PlayerPickUpEvent(Entity picker): picker(picker) {}
};

#endif //TEXTBASED_PLAYERPICKUPEVENT_H
