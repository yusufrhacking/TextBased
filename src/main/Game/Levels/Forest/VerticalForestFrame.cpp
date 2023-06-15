#include "VerticalForestFrame.h"

VerticalForestFrame::VerticalForestFrame(Position referencePosition) : ForestFrame(referencePosition) {
    int forestWidthInTrees = 2;
    Position rightForestPosition = getStartingRightPositionFromWidth(forestWidthInTrees);

    createVerticalForest(forestWidthInTrees, rightForestPosition);
    Position leftForestPosition = {window->getTopLeftPosition()};

    createVerticalForest(forestWidthInTrees, leftForestPosition);

    openAt.openVertical();
}

