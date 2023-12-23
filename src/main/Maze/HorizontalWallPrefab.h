#ifndef TEXTBASED_HORIZONTALWALLPREFAB_H
#define TEXTBASED_HORIZONTALWALLPREFAB_H
#include <memory>
#include "../HighLevel/ECSManager.h"
#include "../Creation/Item.h"
#include "../Creation/CreateItemAtPositionEvent.h"
#include "../Health/OnDeathComponent.h"
#include "../PositionsAndMovement/CollisionComponent.h"
#include "../PositionsAndMovement/LiveComponent.h"
#include "../PositionsAndMovement/PositionComponent.h"
#include "../Creation/CreateLetterAtPositionEvent.h"

extern std::unique_ptr<ECSManager> ecsManager;

struct HorizontalWallPrefab {
    Entity wall;
    explicit HorizontalWallPrefab(Position position) {
        wall = ecsManager->createEntity();
        ecsManager->addComponentToEntity<TextComponent>(wall, TextGenerator::getHorizontalWallText());
        ecsManager->addComponentToEntity<PositionComponent>(wall, position);
        ecsManager->addComponentToEntity<GenericStyleComponent>(wall);
        ecsManager->addComponentToEntity<CollisionComponent>(wall);
        ecsManager->addComponentToEntity<LiveComponent>(wall);
    }

    static Size getSize(){
        return TextComponent::getSurfaceSize(TextGenerator::getHorizontalWallText());
    }
};

#endif //TEXTBASED_HORIZONTALWALLPREFAB_H
