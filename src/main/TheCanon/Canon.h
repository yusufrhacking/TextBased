#ifndef TEXTBASED_CANON_H
#define TEXTBASED_CANON_H

#include <unordered_map>
#include "MapPosition.h"
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
    Canon(Position position);

    void removeEntity(Entity entity);

    void ensurePageExists(MapPosition mapPosition);

    void placeEntity(Entity entity, MapPosition mapPosition);

    std::set<Entity> getEntitiesAtPage(Position position);

    std::set<Entity> getEntitiesAtPage(MapPosition mapPosition);

    static MapPosition getMapPosition(Position position);

    void removeEntityFromPage(Entity entity, MapPosition mapPosition);
};

#endif //TEXTBASED_CANON_H
