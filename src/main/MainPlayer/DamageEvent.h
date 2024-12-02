#ifndef MAINPLAYERDAMAGEEVENT_H
#define MAINPLAYERDAMAGEEVENT_H

#include "../ECSObjects/Entity.h"
#include "../EventSystem/Event.h"

struct DamageEvent: Event {
    Entity damagedEntity{};
    int damage = 1;
    DamageEvent() = default;

    DamageEvent(Entity damagedEntity, int damage): damagedEntity(damagedEntity), damage(damage) {}
};

#endif //MAINPLAYERDAMAGEEVENT_H
