#ifndef TEXTBASED_SUCCESSFULATTACKEVENT_H
#define TEXTBASED_SUCCESSFULATTACKEVENT_H

#include "../EventSystem/Event.h"
#include "AttackType.h"

struct SuccessfulAttackEvent: public Event{
    Entity attacker, victim;
    AttackType attackType;
    SuccessfulAttackEvent(Entity attacker, Entity victim, AttackType attackType):
    attacker(attacker), victim(victim), attackType(attackType){}
};

#endif //TEXTBASED_SUCCESSFULATTACKEVENT_H
