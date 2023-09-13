#ifndef TEXTBASED_PLAYERPICKUPSYSTEM_H
#define TEXTBASED_PLAYERPICKUPSYSTEM_H
#include "PlayerPickUpEvent.h"
#include "../ECSObjects/System.h"

class PlayerPickUpSystem: public System {
public:
    PlayerPickUpSystem();
private:
    const float PICKUP_RANGE = 20;
    void listenToEvents();
    void onPickup(PlayerPickUpEvent& event);

    Position getMainPlayerPosition();
};


#endif //TEXTBASED_PLAYERPICKUPSYSTEM_H
