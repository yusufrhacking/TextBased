#ifndef TEXTBASED_PLACEEVENT_H
#define TEXTBASED_PLACEEVENT_H
#include "../Creation/Item.h"
#include "../EventSystem/Event.h"

struct PlaceEvent: public Event{
    Item type;
    explicit PlaceEvent(Item type): type(type){}
};

#endif //TEXTBASED_PLACEEVENT_H
