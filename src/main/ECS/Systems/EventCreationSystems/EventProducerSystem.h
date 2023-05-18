#ifndef TEXTBASED_EVENTPRODUCERSYSTEM_H
#define TEXTBASED_EVENTPRODUCERSYSTEM_H
#include "../../Design/Objects/System.h"

class EventProducerSystem: public System{
public:
    virtual void update() = 0;
};

#endif //TEXTBASED_EVENTPRODUCERSYSTEM_H
