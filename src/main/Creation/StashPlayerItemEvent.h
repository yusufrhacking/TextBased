
#ifndef TEXTBASED_STASHPLAYERITEMEVENT_H
#define TEXTBASED_STASHPLAYERITEMEVENT_H


#include "../EventSystem/Event.h"
#include "Item.h"

struct StashPlayerItemEvent : public Event {
    Item item;
    explicit StashPlayerItemEvent(Item item): item(item){}

};



#endif //TEXTBASED_STASHPLAYERITEMEVENT_H
