#ifndef PLATFORMLANDINGSYSTEM_H
#define PLATFORMLANDINGSYSTEM_H
#include "ProspectivePlatformLandingEvent.h"
#include "../ECSObjects/System.h"


class PlatformLandingSystem: public System {
    void listenToEvents();
    void onProspectiveLanding(ProspectivePlatformLandingEvent& event);
    void handlePhysics(Entity entity);

public:
    PlatformLandingSystem();
};



#endif //PLATFORMLANDINGSYSTEM_H
