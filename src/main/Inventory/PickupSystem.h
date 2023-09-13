#ifndef TEXTBASED_PICKUPSYSTEM_H
#define TEXTBASED_PICKUPSYSTEM_H


#include "PickupEvent.h"
#include "../ECSObjects/System.h"

class PickupSystem: public System {
public:
    PickupSystem();
private:
    void listenToEvents();
    void onPickup(PickupEvent& event);

    Position getMainPlayerPosition();
};


#endif //TEXTBASED_PICKUPSYSTEM_H
