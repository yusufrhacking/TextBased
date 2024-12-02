#ifndef TEXTBASED_MAINPLAYERACCESSSYSTEM_H
#define TEXTBASED_MAINPLAYERACCESSSYSTEM_H
#include "../ECSObjects/System.h"
#include "KeyboardMovementComponent.h"

class MainPlayerAccessSystem: public System {
public:
    MainPlayerAccessSystem();
    bool hasMainPlayer();
    Entity getMainPlayer();
};


#endif //TEXTBASED_MAINPLAYERACCESSSYSTEM_H
