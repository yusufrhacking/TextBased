#ifndef TEXTBASED_ITEMCOMPONENT_H
#define TEXTBASED_ITEMCOMPONENT_H

#include "CreateItemEvent.h"

struct ItemComponent{
    Item type;
    ItemComponent() = default;
    explicit ItemComponent(Item type): type(type) {}
};

#endif //TEXTBASED_ITEMCOMPONENT_H
