#ifndef TEXTBASED_CANON_H
#define TEXTBASED_CANON_H
#include <unordered_map>
#include "../Helpers/Objects/MapPosition.h"
#include "Page.h"


class Canon {
    std::unordered_map<MapPosition, Page> map;
};


#endif //TEXTBASED_CANON_H
