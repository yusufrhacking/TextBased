#include "Canon.h"

MapPosition Canon::getMapPosition(Position position) {
    int mapX = (int)position.xPos/Page::pageWidth;
    int mapY = (int)position.yPos/Page::pageHeight;
    return {mapX, mapY};
}
