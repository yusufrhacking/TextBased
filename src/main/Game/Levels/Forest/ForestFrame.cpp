#include <spdlog/spdlog.h>
#include "ForestFrame.h"

extern std::unique_ptr<ECSManager> ecsManager;


ForestFrame::ForestFrame(Position referencePosition){
    spdlog::info("Forest Frame created at: {}, {}", referencePosition.xPos, referencePosition.yPos);
    this->frameReferencePosition = referencePosition;
}

void ForestFrame::createVerticalForest(int forestWidthInTrees, Position referencePosition) const {
    unsigned int verticalCapacityForTrees = Window::windowHeight / treeHeight;
    auto stubReferencePosition = createDimensionedUncutForest(forestWidthInTrees,(int)verticalCapacityForTrees, referencePosition);
    stubReferencePosition.xPos = referencePosition.xPos;
    createStubTrees(forestWidthInTrees, stubReferencePosition);
}

//Render as much as you can option instead of dimensioned uncut
Position ForestFrame::createDimensionedForest(int widthInTrees, int heightInTrees, const Position referencePosition) const {
    int verticalCapacityForTrees = getTreeCapacityFromPosition(referencePosition);
    if (heightInTrees < verticalCapacityForTrees){
        return createDimensionedUncutForest(widthInTrees, heightInTrees, referencePosition);
    } else{
        auto stubReferencePosition = createDimensionedUncutForest(widthInTrees, (int)verticalCapacityForTrees, referencePosition);
        return createStubTrees(widthInTrees, stubReferencePosition);
    }
}

Position ForestFrame::createDimensionedUncutForest(int widthInTrees, int heightInTrees, const Position &referencePosition) const {
    Position treePosition = referencePosition;
    for (int heightIndex = 0; heightIndex < heightInTrees; heightIndex++){
        for (int widthIndex = 0; widthIndex < widthInTrees; widthIndex++){
            this->createGenericTreeAtPosition(treePosition);
            treePosition.xPos += (float)treeWidth;
        }
        treePosition.xPos = referencePosition.xPos;
        treePosition.yPos += (float)treeHeight;
    }
    return treePosition;
}

void ForestFrame::createGenericTreeAtPosition(Position position) const {
    Entity tree = ecsManager->createEntity();
    ecsManager->addComponentToEntity<PositionComponent>(tree, frameReferencePosition + position);
    ecsManager->addComponentToEntity<TextComponent>(tree, TextGenerator::getTreeText());
    ecsManager->addComponentToEntity<StyleComponent>(tree);
    ecsManager->addComponentToEntity<CollisionComponent>(tree, ecsManager->getComponentFromEntity<TextComponent>(tree).surfaceSize);
}


Position ForestFrame::createStubTrees(int forestWidthInTrees, Position referencePosition) const {
    std::string stubTreeText = getStubTreeText();

    Position treePosition = referencePosition;
    for (int widthIndex = 0; widthIndex < forestWidthInTrees; widthIndex++){
        this->createStubTreeAtPosition(stubTreeText, treePosition);
        treePosition.xPos += (float)treeWidth;
    }
    return treePosition;
}

std::string ForestFrame::getStubTreeText() const {
    auto linesOfText = splitText(treeSprite.text);

    auto verticalCapacityForTrees = Window::windowHeight / treeHeight;
    auto spaceUsed = verticalCapacityForTrees * treeHeight;
    int verticalRenderSpace = (int)Window::windowHeight - spaceUsed;

    std::string stubTreeText;
    for (const auto & lineCounter : linesOfText){
        if (HEIGHT_OF_A_LINE_OF_TEXT > verticalRenderSpace){
            break;
        }
        stubTreeText += lineCounter;
        verticalRenderSpace -= HEIGHT_OF_A_LINE_OF_TEXT;
    }
    return stubTreeText;
}

std::vector<std::string> ForestFrame::splitText(std::string string) {
    std::istringstream treeStream(string);
    std::vector<std::string> lines;
    std::string line;
    while (std::getline(treeStream, line)) {
        lines.push_back(line + "\n");
    }
    return lines;
}

void ForestFrame::createStubTreeAtPosition(std::string stubTreeText, Position treePosition) const {
    Entity tree = ecsManager->createEntity();
    ecsManager->addComponentToEntity<PositionComponent>(tree, frameReferencePosition + treePosition);
    ecsManager->addComponentToEntity<TextComponent>(tree, stubTreeText);
    ecsManager->addComponentToEntity<StyleComponent>(tree);
    ecsManager->addComponentToEntity<CollisionComponent>(tree, ecsManager->getComponentFromEntity<TextComponent>(tree).surfaceSize);
}

Position ForestFrame::getStartingRightPositionFromWidth(int forestWidthInTrees){
    return {Window::getTopRightPosition().xPos - (float)treeWidth * (float)forestWidthInTrees, Window::getTopRightPosition().yPos};
}

int ForestFrame::getTreeCapacityFromPosition(Position position) const {
    return Window::windowHeight-(int)position.yPos / treeHeight;
}

