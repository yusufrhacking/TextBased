#ifndef TEXTBASED_EVENTCREATIONSYSTEM_H
#define TEXTBASED_EVENTCREATIONSYSTEM_H

#include "../Design/Objects/System.h"
#include "../../Helpers/EventSystem/EventBus/EventBus.h"

class EventCreationSystem: public System{
public:
    virtual void update(std::shared_ptr<EventBus> eventBus) = 0;
};

#endif //TEXTBASED_EVENTCREATIONSYSTEM_H
