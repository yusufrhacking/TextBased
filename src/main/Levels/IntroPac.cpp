#include "IntroPac.h"
#include "../HighLevel/ECSManager.h"
#include "../PositionsAndMovement/PositionComponent.h"
#include "../Inventory/InventoryComponent.h"
#include "../PositionsAndMovement/LiveComponent.h"
#include "../PositionsAndMovement/CollisionComponent.h"
#include "../Health/HealthComponent.h"
#include "../Woodworking/TreePrefab.h"
#include "../Diegesis/EngineerSpeakEvent.h"
#include "../Maze/HorizontalWallPrefab.h"
#include "../Maze/SolidWallRowPrefab.h"
#include "../Maze/SolidColumnPrefab.h"
#include "../Maze/IntroMazePrefab.h"
#include "../MainPlayer/RotateComponent.h"
#include <memory>

#include "../LetterMaze/LetterStreamPrefab.h"

extern std::unique_ptr<ECSManager> ecsManager;
extern std::unique_ptr<EventBus> eventBus;

int speed = 15;

IntroPac::IntroPac(Position startingPosition): startingPosition(startingPosition) {
    witt = ecsManager->createEntity();
    createPlayer();
    IntroMazePrefab{startingPosition};
    // IntroMazePrefab{startingPosition + Position(0, Window::windowHeight)};
    // IntroMazePrefab{startingPosition + Position(Window::windowWidth, 0)};
    // IntroMazePrefab{startingPosition + Position(0, -Window::windowHeight)};
    // IntroMazePrefab{startingPosition + Position(-Window::windowWidth, 0)};
    // const Position letterStartPosition = startingPosition + Position(70, 0);
    // Position leftWallStartPosition = Window::deriveRelativeTopLeft(startingPosition) + Position((float)50, Window::getMiddlePosition().yPos + 25);
    // HalfwayOpenWallRowPrefab{leftWallStartPosition, 36};
    // leftWallStartPosition += Position(0, -50);
    // HalfwayOpenWallRowPrefab{leftWallStartPosition, 36};
    // LetterMazePrefab{letterStartPosition, 0, 33};
    // LetterMazePrefab{Window::deriveRelativeTopLeft(startingPosition) + Position((float)75, Window::getMiddlePosition().yPos), 0, 35};
}

void IntroPac::createPlayer() {
    ecsManager->addComponentToEntity<TextComponent>(witt, "Witt");
    ecsManager->addComponentToEntity<PositionComponent>(witt, startingPosition);
    ecsManager->addComponentToEntity<KeyboardMovementComponent>(witt, std::make_shared<Velocity>(speed, speed));
    ecsManager->addComponentToEntity<GenericStyleComponent>(witt);
    ecsManager->addComponentToEntity<CollisionComponent>(witt);
    ecsManager->addComponentToEntity<InventoryComponent>(witt);
    ecsManager->addComponentToEntity<LiveComponent>(witt);
    ecsManager->addComponentToEntity<HealthComponent>(witt, 10);
    ecsManager->addComponentToEntity<RotationComponent>(witt);
}

void IntroPac::createTrees(Position position) {
    Position treePosition{startingPosition + Position(100, -80)};
    int treeWidth = (int)TextComponent::getSurfaceSize(TextGenerator::getTreeText()).width;
    TreePrefab tree1{treePosition, [this, treePosition]() {
        eventBus->emitEvent<CreateLetterAtPositionEvent>(Letter::E, TreeComponent::findTreeMiddle(treePosition));
    }};
    treePosition = startingPosition + Position(-(treeWidth/2) + 15, -225);
    TreePrefab tree2{treePosition, [this, treePosition]() {
        eventBus->emitEvent<CreateLetterAtPositionEvent>(Letter::X, TreeComponent::findTreeMiddle(treePosition));
    }};
    treePosition = startingPosition + Position(-250, -80);
    TreePrefab tree3{treePosition, [this, treePosition]() {
        eventBus->emitEvent<CreateLetterAtPositionEvent>(Letter::A, TreeComponent::findTreeMiddle(treePosition));
    }};
}

void IntroPac::createWalls() {
    IntroMazePrefab maze{startingPosition};
}
