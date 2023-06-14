#include <spdlog/spdlog.h>
#include "ForestFrame.h"

extern std::unique_ptr<ECSManager> ecsManager;
auto spriteForDimensions = TextComponent(TextGenerator::getTreeText());
auto treeWidth = spriteForDimensions.surfaceSize.width;
auto treeHeight = spriteForDimensions.surfaceSize.height;

ForestFrame::ForestFrame(Position referencePosition){
    spdlog::debug("Forest Frame created at: {}, {}", referencePosition.xPos, referencePosition.yPos);
    this->frameReferencePosition = referencePosition;
    createForests();
}

void ForestFrame::createForests() {
    int forestWidthInTrees = 2;
    Position rightForestPosition = {window->getTopRightPosition().xPos - (float)treeWidth * (float)forestWidthInTrees, window->getTopRightPosition().yPos};

    createVerticalForest(forestWidthInTrees, rightForestPosition);
    Position leftForestPosition = {window->getTopLeftPosition()};

    createVerticalForest(forestWidthInTrees, leftForestPosition);
}

void ForestFrame::createVerticalForest(int forestWidthInTrees, Position referencePosition) const {
    unsigned int verticalCapacityForTrees = Window::windowHeight / treeHeight;

    Position treePosition = referencePosition;
    for (int heightIndex = 0; heightIndex < verticalCapacityForTrees; heightIndex++){
        for (int widthIndex = 0; widthIndex < forestWidthInTrees; widthIndex++){
            createTreeAtPosition(treePosition);
            treePosition.xPos += (float)treeWidth;
        }
        treePosition.xPos = referencePosition.xPos;
        treePosition.yPos += (float)treeHeight;
    }

    unsigned int forestHeightInTrees = (Window::windowHeight / treeHeight) + 1;

//    Position treePosition = referencePosition;
//    for (int widthIndex = 0; widthIndex < forestWidthInTrees; widthIndex++){
//        for (int heightIndex = 0; heightIndex < forestHeightInTrees; heightIndex++){
//            createTreeAtPosition(treePosition);
//            treePosition.yPos += (float)spriteForDimensions.surfaceSize.height;
//        }
//        treePosition.yPos = 0;
//        treePosition.xPos += (float)spriteForDimensions.surfaceSize.width;
//    }
}

void ForestFrame::createTreeAtPosition(Position position) const {
    Entity tree = ecsManager->createEntity();
    ecsManager->addComponentToEntity<PositionComponent>(tree, frameReferencePosition + position);
    ecsManager->addComponentToEntity<TextComponent>(tree, TextGenerator::getTreeText());
    ecsManager->addComponentToEntity<StyleComponent>(tree);
    ecsManager->addComponentToEntity<CollisionComponent>(tree, ecsManager->getComponentFromEntity<TextComponent>(tree).surfaceSize);
}


