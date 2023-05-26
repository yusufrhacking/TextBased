#include "Level1.h"
#include "../GameManager.h"
#include "../../ECS/Components/MainPlayerComponent.h"
#include "../../ECS/Components/TextComponents/TreeComponent.h"

void Level1::setup() {
    createPlayer();
    createBobby();
    createJSON();
    createForests();
}

void Level1::createForests() {
    auto spriteForDimensions = std::make_unique<TextComponent>(TextGenerator::getTreeText());

    int treeWidth = 2;
    Position rightForestPosition = {window->getTopRightPosition().xPos - (float)spriteForDimensions->surfaceSize.width * (float)treeWidth, window->getTopRightPosition().yPos};

    createForest(treeWidth, rightForestPosition);

    Position leftForestPosition = {window->getTopLeftPosition().xPos, window->getTopRightPosition().yPos};

    createForest(treeWidth, leftForestPosition);
}

void Level1::createForest(int widthInTrees, Position startingPosition) const {
    auto spriteForDimensions = std::make_unique<TextComponent>(TextGenerator::getTreeText());

    unsigned int forestWidthInTrees = widthInTrees;
    unsigned int forestHeightInTrees = (window->getWindowHeight() / spriteForDimensions->surfaceSize.height) + 1;

    Position treePosition = startingPosition;
    for (int widthIndex = 0; widthIndex < forestWidthInTrees; widthIndex++){
        for (int heightIndex = 0; heightIndex < forestHeightInTrees; heightIndex++){
            createTreeAtPosition(treePosition);
            treePosition.yPos += (float)spriteForDimensions->surfaceSize.height;
        }
        treePosition.yPos = 0;
        treePosition.xPos += (float)spriteForDimensions->surfaceSize.width;
    }
}

void Level1::createJSON() const {
    Entity json = ecsManager->createEntity();
    ecsManager->addComponentToEntity<PositionComponent>(json, std::make_shared<Position>(400, 300));
    ecsManager->addComponentToEntity<MovementComponent>(json, std::make_shared<Velocity>(0, -18));
    ecsManager->addComponentToEntity<TextComponent>(json, "Jaeson Martin");
    ecsManager->addComponentToEntity<StyleComponent>(json);
    ecsManager->addComponentToEntity<CollisionComponent>(json, ecsManager->getComponentFromEntity<TextComponent>(json).surfaceSize); //.surfaceSize.widthCollisionRange, ecsManager->getComponentFromEntity<TextComponent>(json).surfaceSize.heightCollisionRange);
}

void Level1::createBobby() const {
    Entity tank = ecsManager->createEntity();
    ecsManager->addComponentToEntity<PositionComponent>(tank, std::make_shared<Position>(50, 50));
    ecsManager->addComponentToEntity<MovementComponent>(tank, std::make_shared<Velocity>(20, 0));
    ecsManager->addComponentToEntity<TextComponent>(tank, "Robert C. Martin");
    ecsManager->addComponentToEntity<StyleComponent>(tank);
//    ecsManager->addComponentToEntity<CollisionComponent>(tank, ecsManager->getComponentFromEntity<TextComponent>(tank).surfaceSize);
}

void Level1::createPlayer() {
    Entity giddu = ecsManager->createEntity();
    ecsManager->addComponentToEntity<TextComponent>(giddu, "Giddu");
    ecsManager->addComponentToEntity<PositionComponent>(giddu, window->getMiddlePosition());
    ecsManager->addComponentToEntity<MainPlayerComponent>(giddu, std::make_shared<Velocity>(5, 5));
    ecsManager->addComponentToEntity<StyleComponent>(giddu);
    ecsManager->addComponentToEntity<CollisionComponent>(giddu, ecsManager->getComponentFromEntity<TextComponent>(giddu).surfaceSize);
}

void Level1::createTreeAtPosition(Position position) const {
    Entity tree = ecsManager->createEntity();
    ecsManager->addComponentToEntity<PositionComponent>(tree, position);
    ecsManager->addComponentToEntity<TextComponent>(tree, TextGenerator::getTreeText());
    ecsManager->addComponentToEntity<StyleComponent>(tree);
    ecsManager->addComponentToEntity<CollisionComponent>(tree, ecsManager->getComponentFromEntity<TextComponent>(tree).surfaceSize);
}

