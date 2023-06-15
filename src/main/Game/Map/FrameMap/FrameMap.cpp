#include "FrameMap.h"
#include "FrameCell.h"

FrameMap::FrameMap() {
    map = std::vector<std::vector<FrameCell>>(numRows, std::vector<FrameCell>(numCols));

    for (std::size_t x = 0; x < numRows; ++x) {
        for (std::size_t y = 0; y < numCols; ++y) {
            map[x][y].frame = std::make_unique<Frame>();
            map[x][y].isFilled = true;
            map[x][y].biome = Biome::FOREST;

            if (x > 0) {
                map[x][y].setNeighborFrame(Direction::NORTH, &map[x - 1][y]);
            }
            if (x < numRows - 1) {
                map[x][y].setNeighborFrame(Direction::SOUTH,&map[x + 1][y]);  // Down neighbor
            }
            if (y > 0) {
                map[x][y].setNeighborFrame(Direction::EAST, &map[x][y - 1]);  // Left neighbor
            }
            if (y < numCols - 1) {
                map[x][y].setNeighborFrame(Direction::WEST, &map[x][y + 1]);  // Right neighbor
            }
        }
    }
}
