#ifndef TEXTBASED_ATTACKATTEMPTSYSTEM_H
#define TEXTBASED_ATTACKATTEMPTSYSTEM_H


#include "AttemptedAttackEvent.h"
class AttackAttemptSystem {
private:
    void listenToEvents();
    void onAttackAttempt(AttemptedAttackEvent& event);
public:
    AttackAttemptSystem();
};


#endif //TEXTBASED_ATTACKATTEMPTSYSTEM_H
