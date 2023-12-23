#include "FullBasicLevel.h"
#include "../PositionsAndMovement/PositionComponent.h"
#include "../PositionsAndMovement/CollisionComponent.h"
#include "../MainPlayer/TiedChildComponent.h"
#include "../Woodworking/AxeComponent.h"
#include "../Inventory/InventoryComponent.h"
#include "../PositionsAndMovement/LiveComponent.h"
#include "../Lettering/LetterComponent.h"
#include "../TerminalUI/FixedPositionComponent.h"
#include "../TerminalUI/LiveTerminalRenderSystem.h"
#include "../TerminalUI/TerminalUnderscoreComponent.h"
#include "../Abyz/AbyzComponent.h"
#include "../Health/HealthComponent.h"
#include "../Attacking/AttackableComponent.h"
#include "../Health/OnDeathComponent.h"
#include "../Creation/ItemCreationSystem.h"
#include "../Text/TextGenerator.h"
#include "../Woodworking/TreeComponent.h"
#include "../MainPlayer/MainPlayerComponent.h"
#include "../HighLevel/ECSManager.h"
#include "../Woodworking/TreePrefab.h"
#include "../Abyz/AbyzPrefab.h"
#include "../Lettering/LetterPrefab.h"
#include "../Woodworking/ForestPrefab.h"

extern std::unique_ptr<ECSManager> ecsManager;
extern std::unique_ptr<EventBus> eventBus;


FullBasicLevel::FullBasicLevel(Position startingPosition): startingPosition(startingPosition) {
    witt = ecsManager->createEntity();
    createPlayer();
    ForestPrefab forest{Window::deriveRelativeTopLeft(startingPosition), 2, 5};
    TreePrefab tree{startingPosition + Position(100, 200)};
    AbyzPrefab abyz{startingPosition + Position(400, -150)};
    LetterPrefab a{'a', startingPosition + Position(-100, 0)};
    LetterPrefab x{'x', startingPosition + Position(100, 0)};
    LetterPrefab e{'e', startingPosition + Position(0, -100)};
}

void FullBasicLevel::createPlayer() {
    ecsManager->addComponentToEntity<TextComponent>(witt, "Witt");
    ecsManager->addComponentToEntity<PositionComponent>(witt, startingPosition);
    ecsManager->addComponentToEntity<MainPlayerComponent>(witt, std::make_shared<Velocity>(15, 15));
    ecsManager->addComponentToEntity<GenericStyleComponent>(witt);
    ecsManager->addComponentToEntity<CollisionComponent>(witt);
    ecsManager->addComponentToEntity<InventoryComponent>(witt);
    ecsManager->addComponentToEntity<LiveComponent>(witt);
    ecsManager->addComponentToEntity<HealthComponent>(witt, 10);
}



