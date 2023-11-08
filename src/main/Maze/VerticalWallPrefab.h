
#ifndef TEXTBASED_VERTICALWALLPREFAB_H
#define TEXTBASED_VERTICALWALLPREFAB_H
#include <memory>
#include "../HighLevel/ECSManager.h"
#include "../Creation/Item.h"
#include "../Creation/CreateItemAtPositionEvent.h"
#include "../Health/OnDeathComponent.h"
#include "../PositionsAndMovement/CollisionComponent.h"
#include "../PositionsAndMovement/LiveComponent.h"
#include "../PositionsAndMovement/PositionComponent.h"
#include "../Creation/CreateLetterAtPositionEvent.h"
#include "../Text/TextGenerator.h"

extern std::unique_ptr<ECSManager> ecsManager;

struct VerticalWallPrefab {
    Entity wall;

    explicit VerticalWallPrefab(Position position) {
        wall = ecsManager->createEntity();
        ecsManager->addComponentToEntity<TextComponent>(wall, TextGenerator::getVerticalWallText());
        ecsManager->addComponentToEntity<PositionComponent>(wall, position);
        ecsManager->addComponentToEntity<StyleComponent>(wall);
        ecsManager->addComponentToEntity<CollisionComponent>(wall);
        ecsManager->addComponentToEntity<LiveComponent>(wall);
    }

    static Size getSize(){
        return TextComponent::getSurfaceSize(TextGenerator::getVerticalWallText());
    }
};

#endif //TEXTBASED_VERTICALWALLPREFAB_H
