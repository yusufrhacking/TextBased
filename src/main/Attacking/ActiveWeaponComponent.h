#ifndef TEXTBASED_ACTIVEWEAPONCOMPONENT_H
#define TEXTBASED_ACTIVEWEAPONCOMPONENT_H
#include "../ECSObjects/Entity.h"
#include "../Creation/Item.h"

struct ActiveWeaponComponent{
    Entity entity;
    Item item;
    ActiveWeaponComponent() = default;
    ActiveWeaponComponent(Entity entity, Item item): entity(entity), item(item) {}
};

#endif
