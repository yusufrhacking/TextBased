#ifndef TEXTBASED_PLACESYSTEM_H
#define TEXTBASED_PLACESYSTEM_H

#include "PlaceEvent.h"
#include "../ECSObjects/System.h"

class PlaceSystem: public System {
public:
    PlaceSystem();
private:
    void listenToEvents();
    void onPlacement(PlaceEvent& event);
};


#endif //TEXTBASED_PLACESYSTEM_H
