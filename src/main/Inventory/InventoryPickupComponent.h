#ifndef TEXTBASED_INVENTORYPICKUPCOMPONENT_H
#define TEXTBASED_INVENTORYPICKUPCOMPONENT_H
#include "../Creation/Item.h"

struct InventoryPickupComponent{
    std::string name;
    InventoryPickupComponent() = default;
    explicit InventoryPickupComponent(Item item){
        name = ItemToString(item);
    }
};

#endif //TEXTBASED_INVENTORYPICKUPCOMPONENT_H
