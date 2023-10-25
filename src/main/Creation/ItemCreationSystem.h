#ifndef TEXTBASED_ITEMCREATIONSYSTEM_H
#define TEXTBASED_ITEMCREATIONSYSTEM_H
#include "../ECSObjects/System.h"
#include "CreateItemAtPositionEvent.h"
#include "CreatePlayerItemEvent.h"
#include "../Inventory/StashPlayerItemEvent.h"
#include "CreateItemAtEntityEvent.h"
#include "../Lettering/Letter.h"
#include "CreateLetterAtPositionEvent.h"


class ItemCreationSystem: public System {
public:
    ItemCreationSystem();
private:
    void listenToEvents();
    void onCreateAtPosition(CreateItemAtPositionEvent& event);
    void onCreate(CreatePlayerItemEvent &);
    void createAxe();

    void createWoodPile(Position position);

    void onCreateItemAtEntity(CreateItemAtEntityEvent &);

    void createLetter(Letter letter, Position position);

    void onCreateLetterAtPosition(CreateLetterAtPositionEvent &event);
};


#endif //TEXTBASED_ITEMCREATIONSYSTEM_H
