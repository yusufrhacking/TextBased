#ifndef TEXTBASED_CREATEPLAYERITEMEVENT_H
#define TEXTBASED_CREATEPLAYERITEMEVENT_H

#include "../EventSystem/Event.h"
#include "Item.h"

struct CreatePlayerItemEvent : public Event {
    Item item;
    explicit CreatePlayerItemEvent(Item item): item(item){}

};

#endif //TEXTBASED_CREATEPLAYERITEMEVENT_H
