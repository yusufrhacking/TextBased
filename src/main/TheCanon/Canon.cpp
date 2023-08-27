#include "Canon.h"

std::vector<Entity> Canon::getEntitiesAtPage(Position position){
    return map[getMapPosition(position)].entities;
}

std::vector<Entity> Canon::getEntitiesAtPage(MapPosition mapPosition){
    return map[mapPosition].entities;
}

MapPosition Canon::getMapPosition(Position position) {
    int mapX = (int)position.xPos/Page::pageWidth;
    int mapY = (int)position.yPos/Page::pageHeight;
    return {mapX, mapY};
}
