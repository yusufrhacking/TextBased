#ifndef TEXTBASED_PAGE_H
#define TEXTBASED_PAGE_H

#include <set>
#include "../Rendering/Window.h"
#include "../ECSObjects/Entity.h"

struct Page {
    static int pageWidth;
    static int pageHeight;

    std::set<Entity> entities{};

    Page();
};


#endif //TEXTBASED_PAGE_H
