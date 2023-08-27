#ifndef TEXTBASED_PAGE_H
#define TEXTBASED_PAGE_H

#include <vector>
#include "../ECS/Design/Objects/Entity.h"
#include "../Game/GameSystems/Window/Window.h"

struct Page {
    static int pageWidth;
    static int pageHeight;

    std::vector<Entity> entities{};

    Page();
};


#endif //TEXTBASED_PAGE_H
