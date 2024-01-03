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
    Position startOfIncision{-1, -1};
    Position endOfIncision{-1, -1};
    explicit HalfwayOpenWallRowPrefab(Position position, int length) {
        auto wallSize = TextComponent(TextGenerator::getHorizontalWallText()).getSurfaceSize();
        auto currPosition = position;
        Position wallAdjustment{(float)(wallSize.width), (float)0};
        for (int x=0; x<length; x++) {
            if (x == (length / 2) || x == (length / 2) - 1 || x == (length / 2) + 1) {
                if (startOfIncision.x == -1){
                    startOfIncision = currPosition;
                }
                currPosition = currPosition + wallAdjustment;
                endOfIncision = currPosition;
                continue;
            }
            HorizontalWallPrefab{currPosition};
            currPosition = currPosition + wallAdjustment;
        }
    }
    // explicit HalfwayOpenWallRowPrefab(Position position, int length) {
    //     auto wallSize = TextComponent(TextGenerator::getHorizontalWallText()).getSurfaceSize();
    //     auto currPosition = position;
    //     for (int x = 0; x < length; x++) {
    //         Position wallAdjustment{(float)(wallSize.width), (float)0};
    //         currPosition = currPosition + wallAdjustment;
    //         if (x == length / 2 || x == (length / 2) - 1 || x == (length / 2) + 1) {
    //             if (startOfIncision.xPos == -1){
    //                 startOfIncision = currPosition;
    //             }
    //             endOfIncision = currPosition + wallAdjustment;
    //             continue;
    //         }
    //         HorizontalWallPrefab{currPosition};
    //     }
    // }


};

#endif //TEXTBASED_HALFWAYOPENWALLROWPREFAB_H
