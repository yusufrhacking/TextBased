#ifndef TEXTBASED_ATTACKEXECUTESYSTEM_H
#define TEXTBASED_ATTACKEXECUTESYSTEM_H


#include "SuccessfulAttackEvent.h"

class AttackExecuteSystem {
private:
    void listenToEvents();
    void onAttack(SuccessfulAttackEvent& event);
public:
    AttackExecuteSystem();

};


#endif //TEXTBASED_ATTACKEXECUTESYSTEM_H
