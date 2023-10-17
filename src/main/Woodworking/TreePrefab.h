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

extern std::unique_ptr<ECSManager> ecsManager;
extern std::unique_ptr<EventBus> eventBus;

struct TreePrefab{
    Entity tree;
    explicit TreePrefab(Position position){
        tree = ecsManager->createEntity();
        ecsManager->addComponentToEntity<TextComponent>(tree, TextGenerator::getTreeText());
        Position treePosition = position;
        ecsManager->addComponentToEntity<PositionComponent>(tree, treePosition);
        ecsManager->addComponentToEntity<StyleComponent>(tree);
        ecsManager->addComponentToEntity<CollisionComponent>(tree);
        ecsManager->addComponentToEntity<TreeComponent>(tree);
        ecsManager->addComponentToEntity<LiveComponent>(tree);
        ecsManager->addComponentToEntity<OnDeathComponent>(tree, [this, treePosition]() {
            eventBus->emitEvent<CreateItemAtPositionEvent>(Item::WOOD, TreeComponent::findTreeMiddle(treePosition));
        });
    }
};

#endif //TEXTBASED_TREEPREFAB_H
