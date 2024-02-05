#ifndef PROSPECTIVEPLATFORMLANDINGEVENT_H
#define PROSPECTIVEPLATFORMLANDINGEVENT_H
#include "../EventSystem/Event.h"
#include "../ECSObjects/Entity.h"

struct ProspectivePlatformLandingEvent: Event {
    Entity a, b;
    ProspectivePlatformLandingEvent(Entity a, Entity b): a(a), b(b) {}
};

#endif //PROSPECTIVEPLATFORMLANDINGEVENT_H
