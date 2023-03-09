#pragma clang diagnostic push
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"
#include "GameManager.h"
#include "../ECS/Systems/MovementSystem.h"
#include "TextGenerator.h"

void GameManager::setup() {
    ecsManager->addSystem<MovementSystem>();
    ecsManager->addSystem<RenderSystem>();

    createBobby();
    createJSON();

    auto spriteForDimensions = std::make_unique<SpriteComponent>(TextGenerator::getTreeText());
    //    int treeWidth = 4;
//    Position rightForestPosition = {window->getTopRightPosition().xPos - spriteForDimensions->surfaceSize.width * treeWidth, window->getTopRightPosition().yPos};
//
//    createForest(treeWidth, rightForestPosition);
//
//    Position leftForestPosition = {window->getTopLeftPosition().xPos, window->getTopRightPosition().yPos};
//
//    createForest(treeWidth, leftForestPosition);
}

void GameManager::createForest(int widthInTrees, Position location) const {
    auto spriteForDimensions = std::make_unique<SpriteComponent>(TextGenerator::getTreeText());

    unsigned int forestWidthInTrees = widthInTrees;
    unsigned int forestHeightInTrees = (window->getWindowHeight() / spriteForDimensions->surfaceSize.height) + 1;

    Position treePosition = location;
    for (int widthIndex = 0; widthIndex < forestWidthInTrees; widthIndex++){
        for (int heightIndex = 0; heightIndex < forestHeightInTrees; heightIndex++){
            Entity tree = ecsManager->createEntity();
            ecsManager->addComponentToEntity<TransformComponent>(tree, treePosition);
            ecsManager->addComponentToEntity<SpriteComponent>(tree, TextGenerator::getTreeText());

            treePosition.yPos += spriteForDimensions->surfaceSize.height;
        }
        treePosition.yPos = 0;
        treePosition.xPos += spriteForDimensions->surfaceSize.width;
    }
}

void GameManager::createJSON() const {
    Entity json = ecsManager->createEntity();
    ecsManager->addComponentToEntity<TransformComponent>(json, std::__1::make_shared<Position>(200, 200));
    ecsManager->addComponentToEntity<MovementComponent>(json, std::__1::make_shared<Velocity>(0, -18));
    ecsManager->addComponentToEntity<SpriteComponent>(json, "Jaeson Martin");
}

void GameManager::createBobby() const {
    Entity tank = ecsManager->createEntity();
    ecsManager->addComponentToEntity<TransformComponent>(tank, std::__1::make_shared<Position>(50, 50));
    ecsManager->addComponentToEntity<MovementComponent>(tank, std::__1::make_shared<Velocity>(20, 0));
    ecsManager->addComponentToEntity<SpriteComponent>(tank, "Robert C. Martin");
}

#pragma clang diagnostic pop