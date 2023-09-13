#ifndef TEXTBASED_INVENTORYCOMPONENT_H
#define TEXTBASED_INVENTORYCOMPONENT_H

#include <vector>
#include "../ECSObjects/Entity.h"

struct InventoryComponent{
    std::vector<Entity> items;
    InventoryComponent() = default;
};

#endif //TEXTBASED_INVENTORYCOMPONENT_H
