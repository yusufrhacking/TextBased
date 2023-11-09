#ifndef TEXTBASED_HALFWAYOPENWALLROWPREFAB_H
#define TEXTBASED_HALFWAYOPENWALLROWPREFAB_H
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
#include "HorizontalWallPrefab.h"

extern std::unique_ptr<ECSManager> ecsManager;

struct HalfwayOpenWallRowPrefab {
    Position positionOfIncision{-1, -1};
    explicit HalfwayOpenWallRowPrefab(Position position, int length) {
        auto wallSize = TextComponent(TextGenerator::getHorizontalWallText()).getSurfaceSize();
        for (int x = 0; x < length; x++) {
            auto currPosition = position + Position((float)(wallSize.width * x), (float)0);
            if (x == length / 2 || x == (length / 2) - 1 || x == (length / 2) + 1) {
                if (positionOfIncision.xPos == -1){
                    positionOfIncision = currPosition;
                }
                continue;
            }
            HorizontalWallPrefab{currPosition};
        }
    }


};

#endif //TEXTBASED_HALFWAYOPENWALLROWPREFAB_H
