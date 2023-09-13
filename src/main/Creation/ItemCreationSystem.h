#ifndef TEXTBASED_ITEMCREATIONSYSTEM_H
#define TEXTBASED_ITEMCREATIONSYSTEM_H
#include "../ECSObjects/System.h"
#include "CreateItemAtPositionEvent.h"
#include "CreateItemEvent.h"


class ItemCreationSystem: public System {
public:
    ItemCreationSystem();
private:
    void listenToEvents();
    void onCreateAtPosition(CreateItemAtPositionEvent& event);
    void onCreate(CreateItemEvent &);
    void createAxe();

    void createWoodPile(Position position);

};


#endif //TEXTBASED_ITEMCREATIONSYSTEM_H
