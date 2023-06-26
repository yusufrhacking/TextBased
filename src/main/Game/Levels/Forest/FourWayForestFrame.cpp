#include "FourWayForestFrame.h"

FourWayForestFrame::FourWayForestFrame(Position referencePosition) : ForestFrame(referencePosition) {
    int forestWidthInTrees = 3;
    int forestHeightInTrees = 2;
    Position rightForestPosition = getStartingRightPositionFromWidth(forestWidthInTrees);
    auto finishedRightPosition = createDimensionedForest(forestWidthInTrees, forestHeightInTrees, rightForestPosition);

    auto nextRightPosition = finishedRightPosition + Position(0, treeHeight);
    createDimensionedForest(forestWidthInTrees, forestHeightInTrees, nextRightPosition);

    Position leftForestPosition = {Window::getTopLeftPosition()};
    auto finishedLeftPosition = createDimensionedForest(forestWidthInTrees,forestHeightInTrees, leftForestPosition);

    auto nextLeftPosition = finishedLeftPosition + Position(0, treeHeight);
    createDimensionedForest(forestWidthInTrees, forestHeightInTrees, nextLeftPosition);

    openAt.openEverywhere();
}
