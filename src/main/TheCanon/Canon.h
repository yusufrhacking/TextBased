#ifndef TEXTBASED_CANON_H
#define TEXTBASED_CANON_H

#include <unordered_map>
#include "../Helpers/Objects/MapPosition.h"
#include "Page.h"

namespace std {
    template <>
    struct hash<MapPosition> {
        std::size_t operator()(const MapPosition& pos) const {
            return std::hash<int>()(pos.xPos) ^ std::hash<int>()(pos.yPos);
        }
    };
}

class Canon {
    std::unordered_map<MapPosition, Page, std::hash<MapPosition>> map;

public:
    void addPage(MapPosition mapPosition);

    std::vector<Entity> getEntitiesAtPage(Position position);

    std::vector<Entity> getEntitiesAtPage(MapPosition mapPosition);

    static MapPosition getMapPosition(Position position);
};

#endif //TEXTBASED_CANON_H
