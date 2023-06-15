#include "FrameMap.h"

FrameMap::FrameMap() {
    map = std::vector<std::vector<FrameCell>>(numRows, std::vector<FrameCell>(numCols));
}
