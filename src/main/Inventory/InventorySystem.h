#ifndef TEXTBASED_INVENTORYSYSTEM_H
#define TEXTBASED_INVENTORYSYSTEM_H
#include "PlayerPickUpEvent.h"
#include "../ECSObjects/System.h"
#include "StashPlayerItemEvent.h"
#include "InventoryComponent.h"

class InventorySystem: public System {
public:
    InventorySystem();
private:
    const float PICKUP_RANGE = 20;
    void listenToEvents();
    void onPickup(PlayerPickUpEvent& event);

    void onStash(StashPlayerItemEvent &);

    void stashAxe();

    void pickupItemIntoPlayerInventory(Entity player, Entity pickedUpEntity);
};


#endif //TEXTBASED_INVENTORYSYSTEM_H
