#include "Canon.h"

Canon::Canon(Position position){
    auto mapPosition = getMapPosition(position);
    map.insert({mapPosition, Page()});
}

void Canon::placeEntity(Entity entity, MapPosition mapPosition){
    auto& page = map.at(mapPosition);
    page.entities.insert(entity);
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
