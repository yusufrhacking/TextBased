#ifndef TEXTBASED_TIEDCHILDCOMPONENT_H
#define TEXTBASED_TIEDCHILDCOMPONENT_H
#include "../ECSObjects/Entity.h"
#include <vector>

struct TiedChildComponent{
    std::vector<Entity> entities{};

    TiedChildComponent() = default;

    explicit TiedChildComponent(Entity e){
        entities.push_back(e);
    }

};

#endif
