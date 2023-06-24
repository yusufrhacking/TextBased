#include "SouthOpenForestFrame.h"

SouthOpenForestFrame::SouthOpenForestFrame(Position referencePosition) : ForestFrame(referencePosition) {
    int northWallWidthInTrees = 8;
    int northWallHeightInTrees = 2;
//    Position rightForestPosition = getStartingRightPositionFromWidth(northWallWidthInTrees);
//    auto finishedRightPosition = createDimensionedForest(northWallWidthInTrees, northWallHeightInTrees, rightForestPosition);
//
//    auto nextRightPosition = finishedRightPosition + Position(0, treeHeight);
//    createDimensionedForest(northWallWidthInTrees, northWallHeightInTrees, nextRightPosition);

    Position positionToCenterTreeRow = {15, 0};
    Position leftForestPosition = {window->getTopLeftPosition() + positionToCenterTreeRow};
    auto finishedLeftPosition = createDimensionedForest(northWallWidthInTrees, northWallHeightInTrees, leftForestPosition);

    int sideWallWidthInTrees = 2;
    int sideWallHeightInTrees = 3;

    auto nextLeftPosition = finishedLeftPosition + Position(0, 0);
    createDimensionedForest(sideWallWidthInTrees, sideWallHeightInTrees, nextLeftPosition);

    int horizontalTreeSpaceUsed = northWallWidthInTrees-sideWallHeightInTrees+1;
    auto nextRightPosition = finishedLeftPosition + Position(horizontalTreeSpaceUsed*treeWidth, 0);
    createDimensionedForest(sideWallWidthInTrees, sideWallHeightInTrees, nextRightPosition);

    openAt.openEverywhere();
}
