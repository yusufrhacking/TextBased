#include "GameManager.h"
#include "../ECS/Systems/MovementSystem.h"
#include "TextGenerator.h"

void GameManager::setup() {
    ecsManager->addSystem<MovementSystem>();
    ecsManager->addSystem<RenderSystem>();

    Entity tank = ecsManager->createEntity();
    ecsManager->addComponentToEntity<TransformComponent>(tank, std::make_shared<Position>(50, 50));
    ecsManager->addComponentToEntity<MovementComponent>(tank, std::make_shared<Velocity>(20, 0));
    ecsManager->addComponentToEntity<SpriteComponent>(tank, "Robert C. Martin");


    Entity json = ecsManager->createEntity();
    ecsManager->addComponentToEntity<TransformComponent>(json, std::make_shared<Position>(200, 200));
    ecsManager->addComponentToEntity<MovementComponent>(json, std::make_shared<Velocity>(0, -18));
    ecsManager->addComponentToEntity<SpriteComponent>(json, "Jaeson Martin");

    Entity tree = ecsManager->createEntity();
    ecsManager->addComponentToEntity<TransformComponent>(tree, window->getTopLeftPosition());
    ecsManager->addComponentToEntity<SpriteComponent>(tree, TextGenerator::getTreeText());

    auto sprite = ecsManager->getComponent<SpriteComponent>(tree);
}
