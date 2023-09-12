#ifndef TEXTBASED_CREATEITEMEVENT_H
#define TEXTBASED_CREATEITEMEVENT_H
#include "../EventSystem/Event.h"

enum Item {
    AXE
};

struct CreateItemEvent : public Event {
    Item item;
    explicit CreateItemEvent(Item item): item(item){}
};

#endif //TEXTBASED_CREATEITEMEVENT_H
