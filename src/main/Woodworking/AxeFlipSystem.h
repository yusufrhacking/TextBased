#ifndef AXEFLIPSYSTEM_H
#define AXEFLIPSYSTEM_H
#include "FlipEvent.h"
#include "../ECSObjects/System.h"


class AxeFlipSystem: public System {
private:
    void listenToEvents();
    void onAxeFlip(FlipEvent& event);
public:
    AxeFlipSystem();
};



#endif //AXEFLIPSYSTEM_H
