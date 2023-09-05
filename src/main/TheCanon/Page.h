#ifndef TEXTBASED_PAGE_H
#define TEXTBASED_PAGE_H

#include <set>
#include "../ECS/Design/Objects/Entity.h"
#include "../Rendering/Window.h"

struct Page {
    static int pageWidth;
    static int pageHeight;

    std::set<Entity> entities{};

    Page();
};


#endif //TEXTBASED_PAGE_H
