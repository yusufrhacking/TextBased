#ifndef TEXTBASED_ITEMCREATIONSYSTEM_H
#define TEXTBASED_ITEMCREATIONSYSTEM_H
#include "../ECSObjects/System.h"
#include "CreateItemEvent.h"

static const int AXE_X_OFFSET = 15;

static const int AXE_Y_OFFSET = -45;

class ItemCreationSystem: public System {
public:
    ItemCreationSystem();
private:
    void listenToEvents();
    void onCreate(CreateItemEvent& event);
    void createAxe();
};


#endif //TEXTBASED_ITEMCREATIONSYSTEM_H
