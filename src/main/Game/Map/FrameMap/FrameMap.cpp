#include "FrameMap.h"
#include "FrameCell.h"
#include "../../GameSystems/Window/Window.h"

FrameMap::FrameMap() {
    map = std::vector<std::vector<FrameCell>>(numRows, std::vector<FrameCell>(numCols));
    for (int x = 0; x < numRows; ++x) {
        for (int y = 0; y < numCols; ++y) {
            map[x][y].isFilled = false;
            map[x][y].biome = Biome::BLANK;
            map[x][y].gameReferencePosition = {x * Window::windowWidth, y * Window::windowHeight};

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
