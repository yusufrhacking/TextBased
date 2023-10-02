#ifndef TEXTBASED_HEALTHSYSTEM_H
#define TEXTBASED_HEALTHSYSTEM_H

#include "../Attacking/SuccessfulAttackEvent.h"
#include "../ECSObjects/System.h"

class HealthSystem: public System {
private:
    void listenToEvents();
    void onAttack(SuccessfulAttackEvent& event);
public:
    HealthSystem();

};


#endif //TEXTBASED_HEALTHSYSTEM_H
