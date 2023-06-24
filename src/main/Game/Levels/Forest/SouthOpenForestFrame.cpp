#include "SouthOpenForestFrame.h"

SouthOpenForestFrame::SouthOpenForestFrame(Position referencePosition) : ForestFrame(referencePosition) {
    auto finishedLeftPosition = createNorthWall();

    auto nextLeftPosition = finishedLeftPosition + Position(0, 0);
    createSideWallCluster(nextLeftPosition);

    int horizontalTreeSpaceUsed = northWallWidthInTrees-sideWallHeightInTrees+1;
    auto nextRightPosition = finishedLeftPosition + Position(horizontalTreeSpaceUsed*treeWidth, 0);
    createSideWallCluster(nextRightPosition);

    openAt.south = true;
}
