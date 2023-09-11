#ifndef TEXTBASED_CHOPPINGSYSTEM_H
#define TEXTBASED_CHOPPINGSYSTEM_H
#include "../ECSObjects/System.h"
#include "ChopEvent.h"

class ChoppingSystem: public System {
public:
    ChoppingSystem();
private:
    void listenToEvents();
    void onChop(ChopEvent& event);
};


#endif //TEXTBASED_CHOPPINGSYSTEM_H
