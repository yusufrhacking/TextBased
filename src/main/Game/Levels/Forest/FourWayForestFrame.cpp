#include "FourWayForestFrame.h"

FourWayForestFrame::FourWayForestFrame(Position referencePosition) : ForestFrame(referencePosition) {
    int forestWidthInTrees = 3;
    int forestHeightInTrees = 2;
    Position rightForestPosition = getStartingRightPositionFromWidth(forestWidthInTrees);
    auto finishedPosition = createDimensionedForest(forestWidthInTrees,forestHeightInTrees, rightForestPosition);

    auto nextRightPosition = finishedPosition + Position(0, (finishedPosition.yPos-(finishedPosition.yPos/(float)forestHeightInTrees)));
    createDimensionedForest(forestWidthInTrees, forestHeightInTrees, nextRightPosition);

    Position leftForestPosition = {window->getTopLeftPosition()};
    createDimensionedForest(forestWidthInTrees,forestHeightInTrees, leftForestPosition);

//    Position leftForestPosition = {window->getTopLeftPosition()};
//
//    createVerticalForest(forestWidthInTrees, leftForestPosition);
//    createDimensionedUncutForest(2, 2, referencePosition);
}
