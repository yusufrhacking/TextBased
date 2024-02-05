#ifndef MAINPLAYERDAMAGESYSTEM_H
#define MAINPLAYERDAMAGESYSTEM_H
#include "DamageEvent.h"
#include "../ECSObjects/System.h"


class DamageSystem: public System {
public:
    DamageSystem();
    void listenToEvents();
    void onDamage(DamageEvent& event);
};



#endif //MAINPLAYERDAMAGESYSTEM_H
