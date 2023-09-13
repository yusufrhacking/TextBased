#ifndef TEXTBASED_CREATEITEMATPOSITIONEVENT_H
#define TEXTBASED_CREATEITEMATPOSITIONEVENT_H
#include "../EventSystem/Event.h"
#include "Item.h"


struct CreateItemAtPositionEvent : public Event {
    Item item;
    Position position;

    CreateItemAtPositionEvent(Item item, Position position): item(item), position(position){}
};

#endif //TEXTBASED_CREATEITEMATPOSITIONEVENT_H
