#include <spdlog/spdlog.h>
#include "ForestFrame.h"

extern std::unique_ptr<ECSManager> ecsManager;
auto treeSprite = TextComponent(TextGenerator::getTreeText());
auto treeWidth = treeSprite.surfaceSize.width;
auto treeHeight = treeSprite.surfaceSize.height;

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
    createUncutTrees(forestWidthInTrees, referencePosition);
    createStubTrees(forestWidthInTrees, referencePosition);


    unsigned int forestHeightInTrees = (Window::windowHeight / treeHeight) + 1;

//    Position treePosition = referencePosition;
//    for (int widthIndex = 0; widthIndex < forestWidthInTrees; widthIndex++){
//        for (int heightIndex = 0; heightIndex < forestHeightInTrees; heightIndex++){
//            createTreeAtPosition(treePosition);
//            treePosition.yPos += (float)treeSprite.surfaceSize.height;
//        }
//        treePosition.yPos = 0;
//        treePosition.xPos += (float)treeSprite.surfaceSize.width;
//    }
}

void ForestFrame::createUncutTrees(int forestWidthInTrees, const Position &referencePosition) const {
    unsigned int verticalCapacityForTrees = Window::windowHeight / treeHeight;
    Position treePosition = referencePosition;
    for (int heightIndex = 0; heightIndex < verticalCapacityForTrees; heightIndex++){
        for (int widthIndex = 0; widthIndex < forestWidthInTrees; widthIndex++){
            this->createTreeAtPosition(treePosition);
            treePosition.xPos += (float)treeWidth;
        }
        treePosition.xPos = referencePosition.xPos;
        treePosition.yPos += (float)treeHeight;
    }
}

void ForestFrame::createTreeAtPosition(Position position) const {
    Entity tree = ecsManager->createEntity();
    ecsManager->addComponentToEntity<PositionComponent>(tree, frameReferencePosition + position);
    ecsManager->addComponentToEntity<TextComponent>(tree, TextGenerator::getTreeText());
    ecsManager->addComponentToEntity<StyleComponent>(tree);
    ecsManager->addComponentToEntity<CollisionComponent>(tree, ecsManager->getComponentFromEntity<TextComponent>(tree).surfaceSize);
}


void ForestFrame::createStubTrees(int trees, Position position) const {
    auto linesOfText = splitText(treeSprite.text);

}

std::vector<std::string> ForestFrame::splitText(std::string string) {
    std::istringstream treeStream(string);
    std::vector<std::string> lines;
    std::string line;
    while (std::getline(treeStream, line)) {
        lines.push_back(line);
    }
    return lines;
}

