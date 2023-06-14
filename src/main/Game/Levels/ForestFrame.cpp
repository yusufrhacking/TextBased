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
    auto stubReferencePosition = createUncutTrees(forestWidthInTrees, referencePosition);
    stubReferencePosition.xPos = referencePosition.xPos;
    createStubTrees(forestWidthInTrees, stubReferencePosition);
}

Position ForestFrame::createUncutTrees(int forestWidthInTrees, const Position &referencePosition) const {
    unsigned int verticalCapacityForTrees = Window::windowHeight / treeHeight;
    Position treePosition = referencePosition;
    for (int heightIndex = 0; heightIndex < verticalCapacityForTrees; heightIndex++){
        for (int widthIndex = 0; widthIndex < forestWidthInTrees; widthIndex++){
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


void ForestFrame::createStubTrees(int forestWidthInTrees, Position referencePosition) const {
    std::string stubTreeText = getStubTreeText();

    Position treePosition = referencePosition;
    for (int widthIndex = 0; widthIndex < forestWidthInTrees; widthIndex++){
        this->createStubTreeAtPosition(stubTreeText, treePosition);
        treePosition.xPos += (float)treeWidth;
    }
}

std::string ForestFrame::getStubTreeText() const {
    auto linesOfText = splitText(treeSprite.text);

    auto verticalCapacityForTrees = Window::windowHeight / treeHeight;
    auto spaceUsed = verticalCapacityForTrees * treeHeight;
    auto verticalRenderSpace = Window::windowHeight - spaceUsed;

    std::string stubTreeText;
    for (const auto & lineCounter : linesOfText){
        if (verticalRenderSpace - HEIGHT_OF_A_LINE_OF_TEXT < 0){
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

