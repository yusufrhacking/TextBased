#ifndef TEXTBASED_CREATEITEMATENTITYEVENT_H
#define TEXTBASED_CREATEITEMATENTITYEVENT_H

#include "Item.h"
#include "../ECSObjects/Entity.h"
#include "../EventSystem/Event.h"

struct CreateItemAtEntityEvent: public Event{
    Item item;
    Entity entity;
    CreateItemAtEntityEvent(Item item, Entity entity): item(item), entity(entity) {}
};

#endif //TEXTBASED_CREATEITEMATENTITYEVENT_H
