#pragma clang diagnostic push
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"
#include "GameManager.h"
#include "../ECS/Systems/MovementSystem.h"
#include "TextGenerator.h"
#include "../ECS/Components/ColliderComponent.h"
#include "Level1.h"

void GameManager::setup() {
    Level1 level1;
    level1.setup();
}

#pragma clang diagnostic pop