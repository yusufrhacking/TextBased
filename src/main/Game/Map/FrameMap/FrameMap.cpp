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
            map[x][y].mapPosition = {x, y};
        }
    }
}

std::vector<FrameCell*> FrameMap::getNeighborsOf(MapPosition mapPosition) {
    auto neighbors = std::vector<FrameCell*>(4);

    neighbors[NORTH] = &get(mapPosition + NORTH);
    neighbors[EAST] = &get(mapPosition + EAST);
    neighbors[SOUTH] = &get(mapPosition + SOUTH);
    neighbors[WEST] = &get(mapPosition + WEST);

    return neighbors;
}
