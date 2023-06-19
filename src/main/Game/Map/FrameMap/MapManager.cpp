#include <spdlog/spdlog.h>
#include "FrameCell.h"
#include "FrameGenerator.h"
#include "MapManager.h"
#include "../../Levels/Forest/ForestFrame.h"
#include "../../Levels/Forest/VerticalForestFrame.h"
#include "../../Levels/Forest/FourWayForestFrame.h"

MapManager::MapManager(Position startingPosition) {
    startingMapPosition = getMapPositionFromGamePosition(startingPosition);
    frameMap = std::make_shared<FrameMap>();
    frameGenerator = std::make_unique<FrameGenerator>(frameMap);
    auto& startingCell = frameMap->get(startingMapPosition);
    startingCell.frame = std::make_unique<FourWayForestFrame>(startingPosition);
    startingCell.isFilled = true;
    startingCell.biome = Biome::FOREST;
    applyBiomeAcrossRadius(Biome::FOREST, 2);
}

Frame &MapManager::getFrame(Position position) {
    auto mapPosition = getMapPositionFromGamePosition(position);
    return *frameMap->get(mapPosition).frame;
}

void MapManager::surroundLocation(Position playerPosition) {
    auto playerMapPosition = getMapPositionFromGamePosition(playerPosition);
    for (int deltaX = -1; deltaX <= 1; ++deltaX) {
        for (int deltaY = -1; deltaY <= 1; ++deltaY) {
            if (deltaX == 0 && deltaY == 0) {
                continue;
            }
            auto nextFrameMapPosition = playerMapPosition + MapPosition(deltaX, deltaY);
            frameGenerator->generateFrame(playerMapPosition, nextFrameMapPosition);
        }
    }
}


void MapManager::applyBiomeAcrossRadius(Biome biome, int radius) {
    for (int deltaX = -radius; deltaX < radius; ++deltaX) {
        for (int deltaY = -radius; deltaY < radius; ++deltaY) {
            auto mapPosition = startingMapPosition + MapPosition(deltaX, deltaY);
            frameMap->get(mapPosition).biome = biome;
        }
    }
}

bool MapManager::isFrameAtPositionFilled(Position position) {
    auto mapPosition = getMapPositionFromGamePosition(position);
    return frameMap->get(mapPosition).isFilled;
}

MapPosition MapManager::getMapPositionFromGamePosition(Position playerPosition) {
    int rowPos = (int)playerPosition.xPos/frameWidth;
    int colPos = (int)playerPosition.yPos/frameHeight;
    return {rowPos, colPos};
}

Position MapManager::getGamePositionFromMapPosition(MapPosition mapPosition) {
    int xPos = mapPosition.xPos * frameWidth;
    int yPos = (int)mapPosition.yPos * frameHeight;
    return {static_cast<float>(xPos), static_cast<float>(yPos)};
}
