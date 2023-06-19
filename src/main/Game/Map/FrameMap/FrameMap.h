#ifndef TEXTBASED_FRAMEMAP_H
#define TEXTBASED_FRAMEMAP_H
#include <vector>
#include "FrameCell.h"
#include "../../../Helpers/Objects/MapPosition.h"

class FrameMap {
private:
    std::vector<std::vector<FrameCell>> map;
public:
    static const int numRows = 1000;
    static const int numCols = 1000;
    FrameMap();

    FrameCell& get(MapPosition mapPosition){
        return map[mapPosition.xPos][mapPosition.yPos];
    }

    FrameCell& operator()(std::size_t row, std::size_t col) {
        return map[row][col];
    }

    FrameCell& operator()(MapPosition mapPosition){
        return map[mapPosition.xPos][mapPosition.yPos];
    }

    FrameCell& operator[](MapPosition mapPosition){
        return map[mapPosition.xPos][mapPosition.yPos];
    }
};


#endif //TEXTBASED_FRAMEMAP_H
