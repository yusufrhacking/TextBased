#ifndef TEXTBASED_WALLCOLUMNPREFAB_H
#define TEXTBASED_WALLCOLUMNPREFAB_H
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

struct WallRowPrefab {
    explicit WallRowPrefab(Position position, int length) {
        auto wallSize = TextComponent(TextGenerator::getVerticalWallText()).getSurfaceSize();
        for(int y=0; y<length; y++){
            auto currPosition = position + Position((float)0, (float)(wallSize.height * y));
            Entity wall = ecsManager->createEntity();
            ecsManager->addComponentToEntity<TextComponent>(wall, TextGenerator::getVerticalWallText());
            ecsManager->addComponentToEntity<PositionComponent>(wall, currPosition);
            ecsManager->addComponentToEntity<StyleComponent>(wall);
            ecsManager->addComponentToEntity<CollisionComponent>(wall);
            ecsManager->addComponentToEntity<LiveComponent>(wall);
        }
    }
};

#endif
