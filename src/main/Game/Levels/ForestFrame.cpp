#include <spdlog/spdlog.h>
#include "ForestFrame.h"

extern std::unique_ptr<ECSManager> ecsManager;

ForestFrame::ForestFrame(Position referencePosition){
    spdlog::debug("Forest Frame created at: {}, {}", referencePosition.xPos, referencePosition.yPos);
    this->referencePosition = referencePosition;
//    createJSON();
//    createBobby();
    createForests();
}

void ForestFrame::createForests() {
    auto spriteForDimensions = std::make_unique<TextComponent>(TextGenerator::getTreeText());

    int treeWidth = 2;
    Position rightForestPosition = {window->getTopRightPosition().xPos - (float)spriteForDimensions->surfaceSize.width * (float)treeWidth, window->getTopRightPosition().yPos};

    createForest(treeWidth, rightForestPosition);

    Position leftForestPosition = {window->getTopLeftPosition()};

    createForest(treeWidth, leftForestPosition);
}

void ForestFrame::createForest(int widthInTrees, Position referencePosition) const {
    auto spriteForDimensions = std::make_unique<TextComponent>(TextGenerator::getTreeText());

    unsigned int forestWidthInTrees = widthInTrees;
    unsigned int forestHeightInTrees = (Window::windowHeight / spriteForDimensions->surfaceSize.height) + 1;

    Position treePosition = referencePosition;
    for (int widthIndex = 0; widthIndex < forestWidthInTrees; widthIndex++){
        for (int heightIndex = 0; heightIndex < forestHeightInTrees; heightIndex++){
            createTreeAtPosition(treePosition);
            treePosition.yPos += (float)spriteForDimensions->surfaceSize.height;
        }
        treePosition.yPos = 0;
        treePosition.xPos += (float)spriteForDimensions->surfaceSize.width;
    }
}

void ForestFrame::createJSON() const {
    Entity json = ecsManager->createEntity();
    ecsManager->addComponentToEntity<PositionComponent>(json, referencePosition + Position(400, 300));
    ecsManager->addComponentToEntity<MovementComponent>(json, std::make_shared<Velocity>(0, -18));
    ecsManager->addComponentToEntity<TextComponent>(json, "Jaeson Martin");
    ecsManager->addComponentToEntity<StyleComponent>(json);
    ecsManager->addComponentToEntity<CollisionComponent>(json, ecsManager->getComponentFromEntity<TextComponent>(json).surfaceSize); //.surfaceSize.widthCollisionRange, ecsManager->getComponentFromEntity<TextComponent>(json).surfaceSize.heightCollisionRange);
}

void ForestFrame::createBobby() const {
    Entity tank = ecsManager->createEntity();
    ecsManager->addComponentToEntity<PositionComponent>(tank, referencePosition + Position(50, 50));
    ecsManager->addComponentToEntity<MovementComponent>(tank, std::make_shared<Velocity>(20, 0));
    ecsManager->addComponentToEntity<TextComponent>(tank, "Robert C. Martin");
    ecsManager->addComponentToEntity<StyleComponent>(tank);
//    ecsManager->addComponentToEntity<CollisionComponent>(tank, ecsManager->getComponentFromEntity<TextComponent>(tank).surfaceSize);
}

void ForestFrame::createTreeAtPosition(Position position) const {
    Entity tree = ecsManager->createEntity();
    ecsManager->addComponentToEntity<PositionComponent>(tree, referencePosition + position);
    ecsManager->addComponentToEntity<TextComponent>(tree, TextGenerator::getTreeText());
    ecsManager->addComponentToEntity<StyleComponent>(tree);
    ecsManager->addComponentToEntity<CollisionComponent>(tree, ecsManager->getComponentFromEntity<TextComponent>(tree).surfaceSize);
}


