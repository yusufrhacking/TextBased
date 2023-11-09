#ifndef TEXTBASED_INTROMAZEPREFAB_H
#define TEXTBASED_INTROMAZEPREFAB_H


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
#include "HalfwayOpenWallColumnPrefab.h"
#include "HalfwayOpenWallRowPrefab.h"
#include "HorizontalWallPrefab.h"
#include "VerticalWallPrefab.h"
#include "SolidWallRowPrefab.h"
#include "SolidColumnPrefab.h"

extern std::unique_ptr<ECSManager> ecsManager;

struct IntroMazePrefab {
    HalfwayOpenWallRowPrefab topRow;
    HalfwayOpenWallColumnPrefab leftColumn;
    HalfwayOpenWallRowPrefab bottomRow;
    HalfwayOpenWallColumnPrefab rightColumn;

    explicit IntroMazePrefab(Position startingPosition)
            : topRow(calculateTopRow(startingPosition)),
              leftColumn(calculateLeftColumn(startingPosition)),
              bottomRow(calculateBottomRow(startingPosition)),
              rightColumn(calculateRightColumn(startingPosition))
    {
    }

private:
    static HalfwayOpenWallRowPrefab calculateTopRow(Position startingPosition) {
        Position wallStartPosition = Window::deriveRelativeTopLeft(startingPosition);
        int horizontalLengthInWalls = 40;
        return HalfwayOpenWallRowPrefab{wallStartPosition, horizontalLengthInWalls};
    }

    static HalfwayOpenWallColumnPrefab calculateLeftColumn(Position startingPosition) {
        Position wallStartPosition = Window::deriveRelativeTopLeft(startingPosition);
        int verticalLengthInWalls = 15;
        return HalfwayOpenWallColumnPrefab{wallStartPosition, verticalLengthInWalls};
    }

    static HalfwayOpenWallRowPrefab calculateBottomRow(Position startingPosition) {
        Position bottomLeft = Window::deriveRelativeBottomLeft(startingPosition);
        Position bottomWallVisibilityAdjustment = {
                (float)VerticalWallPrefab::getSize().width,
                -3 * (float)HorizontalWallPrefab::getSize().height
        };
        Position newBottomLeft = bottomLeft + bottomWallVisibilityAdjustment;
        int horizontalLengthInWalls = 40;
        return HalfwayOpenWallRowPrefab{newBottomLeft, horizontalLengthInWalls};
    }

    static HalfwayOpenWallColumnPrefab calculateRightColumn(Position startingPosition) {
        Position topRight = Window::deriveRelativeTopRight(startingPosition);
        Position rightWallVisibilityAdjustment = {
                (float)(2 * VerticalWallPrefab::getSize().width), 0.0
        };
        Position newTopRight = topRight - rightWallVisibilityAdjustment;
        int verticalLengthInWalls = 15;
        return HalfwayOpenWallColumnPrefab{newTopRight, verticalLengthInWalls};
    }
};



#endif //TEXTBASED_INTROMAZEPREFAB_H
