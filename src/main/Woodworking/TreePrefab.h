#ifndef TEXTBASED_TREEPREFAB_H
#define TEXTBASED_TREEPREFAB_H
#include <memory>
#include "../HighLevel/ECSManager.h"
#include "../Creation/Item.h"
#include "../Creation/CreateItemAtPositionEvent.h"
#include "TreeComponent.h"
#include "../Health/OnDeathComponent.h"
#include "../PositionsAndMovement/CollisionComponent.h"
#include "../PositionsAndMovement/LiveComponent.h"
#include "../PositionsAndMovement/PositionComponent.h"
#include "ChoppableComponent.h"
#include "../Creation/CreateLetterAtPositionEvent.h"

extern std::unique_ptr<ECSManager> ecsManager;
extern std::unique_ptr<EventBus> eventBus;

using OnDeathFunction = std::function<void(void)>;

struct TreePrefab{
    Entity tree;
    int breakAt = 7;
    explicit TreePrefab(Position position){
        tree = ecsManager->createEntity();
        ecsManager->addComponentToEntity<TextComponent>(tree, TextGenerator::getTreeText());
        Position treePosition = position;
        ecsManager->addComponentToEntity<PositionComponent>(tree, treePosition);
        ecsManager->addComponentToEntity<GenericStyleComponent>(tree);
        ecsManager->addComponentToEntity<CollisionComponent>(tree);
        ecsManager->addComponentToEntity<TreeComponent>(tree);
        ecsManager->addComponentToEntity<LiveComponent>(tree);
        ecsManager->addComponentToEntity<OnDeathComponent>(tree, [this, treePosition]() {
            eventBus->emitEvent<CreateItemAtPositionEvent>(Item::WOOD, TreeComponent::findTreeMiddle(treePosition));
            // eventBus->emitEvent<CreateLetterAtPositionEvent>(Letter::A, TreeComponent::findTreeMiddle(treePosition));
        });
        ecsManager->addComponentToEntity<ChoppableComponent>(tree, breakAt);
    }

    TreePrefab(Position position, const OnDeathFunction& onDeathFn) {
        tree = ecsManager->createEntity();
        ecsManager->addComponentToEntity<TextComponent>(tree, TextGenerator::getTreeText());
        Position treePosition = position;
        ecsManager->addComponentToEntity<PositionComponent>(tree, treePosition);
        ecsManager->addComponentToEntity<GenericStyleComponent>(tree);
        ecsManager->addComponentToEntity<CollisionComponent>(tree);
        ecsManager->addComponentToEntity<TreeComponent>(tree);
        ecsManager->addComponentToEntity<LiveComponent>(tree);
        ecsManager->addComponentToEntity<OnDeathComponent>(tree, onDeathFn);
        ecsManager->addComponentToEntity<ChoppableComponent>(tree, breakAt);
    }

};

#endif //TEXTBASED_TREEPREFAB_H
