#include "VerticalForestFrame.h"

VerticalForestFrame::VerticalForestFrame(Position referencePosition) : ForestFrame(referencePosition) {
    createForests();
}

void VerticalForestFrame::createForests() {
    int forestWidthInTrees = 2;
    Position rightForestPosition = {window->getTopRightPosition().xPos - (float)treeWidth * (float)forestWidthInTrees, window->getTopRightPosition().yPos};

    createVerticalForest(forestWidthInTrees, rightForestPosition);
    Position leftForestPosition = {window->getTopLeftPosition()};

    createVerticalForest(forestWidthInTrees, leftForestPosition);
}

