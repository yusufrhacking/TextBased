#ifndef TEXTBASED_FRAMEMAP_H
#define TEXTBASED_FRAMEMAP_H
#include <vector>
#include "FrameCell.h"

class FrameMap {
private:
    std::vector<std::vector<FrameCell>> map;
public:
    static const int numRows = 10000;
    static const int numCols = 10000;
    FrameMap();

    FrameCell& operator()(std::size_t row, std::size_t col) {
        return map[row][col];
    }
};


#endif //TEXTBASED_FRAMEMAP_H
