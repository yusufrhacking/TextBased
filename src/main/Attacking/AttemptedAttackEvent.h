#ifndef TEXTBASED_ATTEMPTEDATTACKEVENT_H
#define TEXTBASED_ATTEMPTEDATTACKEVENT_H

#include "../EventSystem/Event.h"
#include "../ECSObjects/Entity.h"

struct AttemptedAttackEvent: public Event{
    Entity attacker;
    explicit AttemptedAttackEvent(Entity entity): attacker(entity){}
};

#endif //TEXTBASED_ATTEMPTEDATTACKEVENT_H
