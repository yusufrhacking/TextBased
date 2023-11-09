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
    HalfwayOpenWallRowPrefab middleRow;
    SolidColumnPrefab leftTopMiddleColumn;
    SolidColumnPrefab rightTopMiddleColumn;
    SolidColumnPrefab leftBottomMiddleColumn;
    SolidColumnPrefab rightBottomMiddleColumn;

    static int verticalLengthInWalls;
    static int horizontalLengthInWalls;

    explicit IntroMazePrefab(Position startingPosition)
            : topRow(calculateTopRow(startingPosition)),
              leftColumn(calculateLeftColumn(startingPosition)),
              bottomRow(calculateBottomRow(startingPosition)),
              rightColumn(calculateRightColumn(startingPosition)),
              middleRow(leftColumn.positionOfIncision, horizontalLengthInWalls),
              leftTopMiddleColumn(topRow.startOfIncision, 7),
              rightTopMiddleColumn(topRow.endOfIncision, 7),
              leftBottomMiddleColumn(topRow.startOfIncision, 7),
              rightBottomMiddleColumn(topRow.endOfIncision, 7)
    {

    }

private:
    static HalfwayOpenWallRowPrefab calculateTopRow(Position startingPosition) {
        Position wallStartPosition = Window::deriveRelativeTopLeft(startingPosition);
        return HalfwayOpenWallRowPrefab{wallStartPosition, horizontalLengthInWalls};
    }

    static HalfwayOpenWallColumnPrefab calculateLeftColumn(Position startingPosition) {
        Position wallStartPosition = Window::deriveRelativeTopLeft(startingPosition);
        return HalfwayOpenWallColumnPrefab{wallStartPosition, verticalLengthInWalls};
    }

    static HalfwayOpenWallRowPrefab calculateBottomRow(Position startingPosition) {
        Position bottomLeft = Window::deriveRelativeBottomLeft(startingPosition);
        Position bottomWallVisibilityAdjustment = {
                (float)VerticalWallPrefab::getSize().width,
                -3 * (float)HorizontalWallPrefab::getSize().height
        };
        Position newBottomLeft = bottomLeft + bottomWallVisibilityAdjustment;
        return HalfwayOpenWallRowPrefab{newBottomLeft, horizontalLengthInWalls};
    }

    static HalfwayOpenWallColumnPrefab calculateRightColumn(Position startingPosition) {
        Position topRight = Window::deriveRelativeTopRight(startingPosition);
        Position rightWallVisibilityAdjustment = {
                (float)(2 * VerticalWallPrefab::getSize().width), 0.0
        };
        Position newTopRight = topRight - rightWallVisibilityAdjustment;
        return HalfwayOpenWallColumnPrefab{newTopRight, verticalLengthInWalls};
    }
};



#endif //TEXTBASED_INTROMAZEPREFAB_H
