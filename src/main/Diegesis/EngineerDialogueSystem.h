#ifndef TEXTBASED_ENGINEERDIALOGUESYSTEM_H
#define TEXTBASED_ENGINEERDIALOGUESYSTEM_H


#include "../Lettering/CharacterDepositEvent.h"
#include "../ECSObjects/System.h"
#include "../Creation/CreateItemAtPositionEvent.h"
#include "../Creation/CreatePlayerItemEvent.h"
#include "../Inventory/PlayerPickUpEvent.h"
#include "../Inventory/StashPlayerItemEvent.h"
#include "../Inventory/PlaceEvent.h"

class EngineerDialogueSystem: public System {
public:
    EngineerDialogueSystem();
private:
    bool isFirstLetter = true;
    void listenToEvents();
    void onLetter(CharacterDepositEvent& event); //on deposit, check if first one, then send this message
    void onWoodSpawn(CreateItemAtPositionEvent & event);

    void onCreateAxe(CreatePlayerItemEvent & event);

    void onPickup(PlayerPickUpEvent & event);

    void onPlace(PlaceEvent & event);
};


#endif //TEXTBASED_ENGINEERDIALOGUESYSTEM_H
