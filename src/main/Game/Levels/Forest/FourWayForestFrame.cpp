#include "FourWayForestFrame.h"

FourWayForestFrame::FourWayForestFrame(Position referencePosition) : ForestFrame(referencePosition) {
    int forestWidthInTrees = 3;
    int forestHeightInTrees = 2;
    Position rightForestPosition = getStartingRightPositionFromWidth(forestWidthInTrees);

    createDimensionedUncutForest(forestWidthInTrees,forestHeightInTrees, rightForestPosition);
    Position leftForestPosition = {window->getTopLeftPosition()};
    createDimensionedUncutForest(forestWidthInTrees,forestHeightInTrees, leftForestPosition);

//    Position leftForestPosition = {window->getTopLeftPosition()};
//
//    createVerticalForest(forestWidthInTrees, leftForestPosition);
//    createDimensionedUncutForest(2, 2, referencePosition);
}
