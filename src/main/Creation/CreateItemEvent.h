#ifndef TEXTBASED_CREATEITEMEVENT_H
#define TEXTBASED_CREATEITEMEVENT_H
#include "../EventSystem/Event.h"

enum Item {
    AXE,
    WOOD_PILE
};

struct CreateItemEvent : public Event {
    Item item;
    Position position;
    explicit CreateItemEvent(Item item): item(item){
        position = {0, 0};
    }

    CreateItemEvent(Item item, Position position): item(item), position(position){}
};

#endif //TEXTBASED_CREATEITEMEVENT_H
