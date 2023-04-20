#include "Level1.h"

void Level1::setup() {
    ecsManager->addSystem<MovementSystem>();
    ecsManager->addSystem<RenderSystem>();

    createBobby();
    createJSON();

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
            Entity tree = ecsManager->createEntity();
            ecsManager->addComponentToEntity<PositionComponent>(tree, treePosition);
            ecsManager->addComponentToEntity<TextComponent>(tree, TextGenerator::getTreeText());
            ecsManager->addComponentToEntity<StyleComponent>(tree);

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
    ecsManager->addComponentToEntity<ColliderComponent>(json, ecsManager->getComponentFromEntity<TextComponent>(json).surfaceSize); //.surfaceSize.widthCollisionRange, ecsManager->getComponentFromEntity<TextComponent>(json).surfaceSize.heightCollisionRange);
}

void Level1::createBobby() const {
    Entity tank = ecsManager->createEntity();
    ecsManager->addComponentToEntity<PositionComponent>(tank, std::make_shared<Position>(50, 50));
    ecsManager->addComponentToEntity<MovementComponent>(tank, std::make_shared<Velocity>(20, 0));
    ecsManager->addComponentToEntity<TextComponent>(tank, "Robert C. Martin");
    ecsManager->addComponentToEntity<StyleComponent>(tank);
}