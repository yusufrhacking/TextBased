#ifndef TEXTBASED_ITEMCREATIONSYSTEM_H
#define TEXTBASED_ITEMCREATIONSYSTEM_H
#include "../ECSObjects/System.h"
#include "CreateItemAtPositionEvent.h"
#include "CreatePlayerItemEvent.h"
#include "../Inventory/StashPlayerItemEvent.h"


class ItemCreationSystem: public System {
public:
    ItemCreationSystem();
private:
    void listenToEvents();
    void onCreateAtPosition(CreateItemAtPositionEvent& event);
    void onCreate(CreatePlayerItemEvent &);
    void onStash(StashPlayerItemEvent &);
    void createAxe();

    void createWoodPile(Position position);

    void stashAxe();
};


#endif //TEXTBASED_ITEMCREATIONSYSTEM_H
