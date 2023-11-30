#ifndef TEXTBASED_TIEDCHILDCOMPONENT_H
#define TEXTBASED_TIEDCHILDCOMPONENT_H
#include "../ECSObjects/Entity.h"
#include <vector>
#include <set>

struct TiedChildComponent{
    std::set<Entity> entities{};

    TiedChildComponent() = default;

    explicit TiedChildComponent(Entity e){
        entities.insert(e);
    }

};

#endif
