#ifndef TEXTBASED_EVENTSYSTEM_H
#define TEXTBASED_EVENTSYSTEM_H
#include "../Design/Objects/System.h"
#include "../../Helpers/EventSystem/EventBus/EventBus.h"

class EventSystem: public System{
public:
    virtual void update(std::shared_ptr<EventBus> eventBus) = 0;
};

#endif //TEXTBASED_EVENTSYSTEM_H
