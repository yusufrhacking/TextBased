#ifndef TEXTBASED_ATTACKATTEMPTSYSTEM_H
#define TEXTBASED_ATTACKATTEMPTSYSTEM_H


#include "AttemptedAttackEvent.h"
#include "../ECSObjects/System.h"

class AttackAttemptSystem: public System {
private:
    const float ATTACK_RANGE = 10;
    void listenToEvents();
    void onAttackAttempt(AttemptedAttackEvent& event);
public:
    AttackAttemptSystem();
};


#endif //TEXTBASED_ATTACKATTEMPTSYSTEM_H
