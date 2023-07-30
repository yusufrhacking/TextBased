#ifndef TEXTBASED_PAGE_H
#define TEXTBASED_PAGE_H

#include <vector>
#include "../ECS/Design/Objects/Entity.h"
#include "../Game/GameSystems/Window/Window.h"

struct Page {
    std::vector<Entity> entities{};
    static int pageWidth;
    static int pageHeight;
};


#endif //TEXTBASED_PAGE_H
