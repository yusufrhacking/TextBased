#ifndef TEXTBASED_PAGE_H
#define TEXTBASED_PAGE_H

#include <vector>
#include "../ECS/Design/Objects/Entity.h"

struct Page {
    std::vector<Entity> entities{};
};


#endif //TEXTBASED_PAGE_H
