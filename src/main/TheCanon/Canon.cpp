#include <spdlog/spdlog.h>
#include "Canon.h"

Canon::Canon(Position position){
    auto mapPosition = getMapPosition(position);
    map.insert({mapPosition, Page()});
}

void Canon::placeEntity(Entity entity, MapPosition mapPosition){
    ensurePageExists(mapPosition);
    auto& page = map.at(mapPosition);
    page.entities.insert(entity);
    spdlog::trace("Placed entity {} at Page {}, {}", entity.getId(), mapPosition.xPos, mapPosition.yPos);
}


void Canon::removeEntityFromPage(Entity entity, MapPosition mapPosition) {
    auto& page = map.at(mapPosition);
    page.entities.erase(entity);
    spdlog::trace("Erased entity {} at Page {}, {}", entity.getId(), mapPosition.xPos, mapPosition.yPos);
}

void Canon::removeEntity(Entity entity){
    for (auto& pair : map) {
        const auto& position = pair.first;
        auto& entitiesSet = pair.second.entities;

        if (entitiesSet.contains(entity)) {
            entitiesSet.erase(entity);
        }
    }
}

void Canon::ensurePageExists(MapPosition mapPosition){
    if (map.find(mapPosition) == map.end()) {
        map.insert({mapPosition, Page()});
    }
}

std::set<Entity> Canon::getEntitiesAtPage(Position position){
    return map[getMapPosition(position)].entities;
}

std::set<Entity> Canon::getEntitiesAtPage(MapPosition mapPosition){
    return map[mapPosition].entities;
}

MapPosition Canon::getMapPosition(Position position) {
    int mapX = (int)position.xPos/Page::pageWidth;
    int mapY = (int)position.yPos/Page::pageHeight;
    return {mapX, mapY};
}

