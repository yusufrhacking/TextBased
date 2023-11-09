#ifndef TEXTBASED_PLAYERROTATESYSTEM_H
#define TEXTBASED_PLAYERROTATESYSTEM_H


#include "../ECSObjects/System.h"
#include "RotateEvent.h"

class PlayerRotateSystem: public System {
public:
    PlayerRotateSystem();
    void listenToEvents();
    void onRotate(RotateEvent& event);
};


#endif //TEXTBASED_PLAYERROTATESYSTEM_H
