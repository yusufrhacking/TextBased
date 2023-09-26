#ifndef TEXTBASED_INVENTORYCOMPONENT_H
#define TEXTBASED_INVENTORYCOMPONENT_H

#include <vector>
#include "../ECSObjects/Entity.h"
#include "Inventory.h"

struct InventoryComponent{
    Inventory inventory;
    InventoryComponent() = default;
};

#endif //TEXTBASED_INVENTORYCOMPONENT_H
