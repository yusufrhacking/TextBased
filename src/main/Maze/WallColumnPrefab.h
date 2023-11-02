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
#include "VerticalWallPrefab.h"

extern std::unique_ptr<ECSManager> ecsManager;

struct WallColumnPrefab {
    explicit WallColumnPrefab(Position position, int length) {
        auto wallSize = TextComponent(TextGenerator::getVerticalWallText()).getSurfaceSize();
        for(int y=0; y<length; y++){
            auto currPosition = position + Position((float)0, (float)(wallSize.height * y));
            VerticalWallPrefab wall{currPosition};
        }
    }
};

#endif
