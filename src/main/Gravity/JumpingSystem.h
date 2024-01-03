#ifndef JUMPINGSYSTEM_H
#define JUMPINGSYSTEM_H
#include "../ECSObjects/EventConsumerSystem.h"
#include "../TextInput/GameKeyEvent.h"


class JumpingSystem: public System {
    void onKeyPressed(GameKeyEvent& event);
public:
    JumpingSystem();
};



#endif //JUMPINGSYSTEM_H
