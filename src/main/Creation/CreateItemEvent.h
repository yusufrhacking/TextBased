#ifndef TEXTBASED_CREATEITEMEVENT_H
#define TEXTBASED_CREATEITEMEVENT_H

#include "../EventSystem/Event.h"
#include "Item.h"

struct CreateItemEvent : public Event {
    Item item;
    explicit CreateItemEvent(Item item): item(item){}

};

#endif //TEXTBASED_CREATEITEMEVENT_H
