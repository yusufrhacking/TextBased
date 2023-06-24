#include "SouthEastOpenForestFrame.h"

SouthEastOpenForestFrame::SouthEastOpenForestFrame(Position referencePosition) : ForestFrame(referencePosition) {
    auto finishedLeftPosition = createNorthWall();

    auto nextLeftPosition = finishedLeftPosition + Position(0, 0);
    createSideWallCluster(nextLeftPosition);
    openAt.east = true;
    openAt.south = true;
}
