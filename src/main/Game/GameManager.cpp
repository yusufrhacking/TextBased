#pragma clang diagnostic push
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"
#include "GameManager.h"
#include "../ECS/Systems/UpdateSystems/MovementSystem.h"
#include "TextGenerator.h"
#include "../ECS/Components/CollisionComponent.h"
#include "Levels/Level1.h"

void GameManager::setup() {
    ecsManager->setup();
    Level1 level1;
    level1.setup();
}

#pragma clang diagnostic pop