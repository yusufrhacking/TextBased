#include "Level1.h"
#include "../GameManager.h"
#include "../../ECS/Components/MainPlayerComponent.h"
#include "../../ECS/Components/TextComponents/TreeComponent.h"

Position startingPosition = {1000, 1000};

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
    ecsManager->addComponentToEntity<PositionComponent>(json, startingPosition+Position(400, 300));
    ecsManager->addComponentToEntity<MovementComponent>(json, std::make_shared<Velocity>(0, -18));
    ecsManager->addComponentToEntity<TextComponent>(json, "Jaeson Martin");
    ecsManager->addComponentToEntity<StyleComponent>(json);
    ecsManager->addComponentToEntity<CollisionComponent>(json, ecsManager->getComponentFromEntity<TextComponent>(json).surfaceSize); //.surfaceSize.widthCollisionRange, ecsManager->getComponentFromEntity<TextComponent>(json).surfaceSize.heightCollisionRange);
}

void Level1::createBobby() const {
    Entity tank = ecsManager->createEntity();
    ecsManager->addComponentToEntity<PositionComponent>(tank, startingPosition+Position(50, 50));
    ecsManager->addComponentToEntity<MovementComponent>(tank, std::make_shared<Velocity>(20, 0));
    ecsManager->addComponentToEntity<TextComponent>(tank, "Robert C. Martin");
    ecsManager->addComponentToEntity<StyleComponent>(tank);
//    ecsManager->addComponentToEntity<CollisionComponent>(tank, ecsManager->getComponentFromEntity<TextComponent>(tank).surfaceSize);
}

void Level1::createPlayer() {
    Entity witt = ecsManager->createEntity();
    ecsManager->addComponentToEntity<TextComponent>(witt, "Witt");
    ecsManager->addComponentToEntity<PositionComponent>(witt, startingPosition+window->getMiddlePosition());
    ecsManager->addComponentToEntity<MainPlayerComponent>(witt, std::make_shared<Velocity>(5, 5));
    ecsManager->addComponentToEntity<StyleComponent>(witt);
    ecsManager->addComponentToEntity<CollisionComponent>(witt, ecsManager->getComponentFromEntity<TextComponent>(witt).surfaceSize);
}

void Level1::createTreeAtPosition(Position position) const {
    Entity tree = ecsManager->createEntity();
    ecsManager->addComponentToEntity<PositionComponent>(tree, startingPosition+position);
    ecsManager->addComponentToEntity<TextComponent>(tree, TextGenerator::getTreeText());
    ecsManager->addComponentToEntity<StyleComponent>(tree);
    ecsManager->addComponentToEntity<CollisionComponent>(tree, ecsManager->getComponentFromEntity<TextComponent>(tree).surfaceSize);
}

