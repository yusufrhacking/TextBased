#include "IntroPac.h"
#include "../HighLevel/ECSManager.h"
#include "../PositionsAndMovement/PositionComponent.h"
#include "../Inventory/InventoryComponent.h"
#include "../PositionsAndMovement/LiveComponent.h"
#include "../PositionsAndMovement/CollisionComponent.h"
#include "../Health/HealthComponent.h"
#include "../Woodworking/TreePrefab.h"
#include "../Diegesis/EngineerSpeakEvent.h"
#include "../Maze/WallPrefab.h"
#include "../Maze/WallRowPrefab.h"
#include <memory>

extern std::unique_ptr<ECSManager> ecsManager;
extern std::unique_ptr<EventBus> eventBus;

IntroPac::IntroPac(Position startingPosition): startingPosition(startingPosition) {
    witt = ecsManager->createEntity();
    createPlayer();
    createTrees(startingPosition);
    eventBus->emitEvent<EngineerSpeakEvent>("try `punch`");
    createWalls();
}

void IntroPac::createPlayer() {
    ecsManager->addComponentToEntity<TextComponent>(witt, "Witt");
    ecsManager->addComponentToEntity<PositionComponent>(witt, startingPosition);
    ecsManager->addComponentToEntity<MainPlayerComponent>(witt, std::make_shared<Velocity>(15, 15));
    ecsManager->addComponentToEntity<StyleComponent>(witt);
    ecsManager->addComponentToEntity<CollisionComponent>(witt);
    ecsManager->addComponentToEntity<InventoryComponent>(witt);
    ecsManager->addComponentToEntity<LiveComponent>(witt);
    ecsManager->addComponentToEntity<HealthComponent>(witt, 10);
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
    WallRowPrefab wall{startingPosition + Position(300, 150), 5};
}
