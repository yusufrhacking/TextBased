#ifndef TEXTBASED_PLAYERPICKUPSYSTEM_H
#define TEXTBASED_PLAYERPICKUPSYSTEM_H
#include "PlayerPickUpEvent.h"
#include "../ECSObjects/System.h"
#include "../Creation/StashPlayerItemEvent.h"
#include "InventoryComponent.h"

class PlayerPickUpSystem: public System {
public:
    PlayerPickUpSystem();
private:
    const float PICKUP_RANGE = 20;
    void listenToEvents();
    void onPickup(PlayerPickUpEvent& event);

    void onStash(StashPlayerItemEvent &);

    void stashAxe();

    void pickupItemIntoPlayerInventory(Entity player, Entity pickedUpEntity);
};


#endif //TEXTBASED_PLAYERPICKUPSYSTEM_H
