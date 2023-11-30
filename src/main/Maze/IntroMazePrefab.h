#ifndef TEXTBASED_INTROMAZEPREFAB_H
#define TEXTBASED_INTROMAZEPREFAB_H
#include <memory>

#include "FourTreePrefab.h"
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
#include "../Lettering/LetterPickupSystem.h"
#include "../LetterMaze/LetterStreamPrefab.h"
#include "../LetterMaze/VerticalLetterStreamPrefab.h"
#include "../Woodworking/TreePrefab.h"
#include "../Abyz/AbyzPrefab.h"

extern std::unique_ptr<ECSManager> ecsManager;

struct IntroMazePrefab {
    HalfwayOpenWallRowPrefab topRow;
    HalfwayOpenWallColumnPrefab leftColumn;
    HalfwayOpenWallRowPrefab bottomRow;
    HalfwayOpenWallColumnPrefab rightColumn;

    static int verticalLengthInWalls;
    static int outerHorizontalLengthInWalls;
    static int innerHorizontalLengthInWalls;

    static float horizontalRowStartOffset;
    static float BOTTOM_SPACING_MULTIPLIER;

    // static Position relativeTreeCenterSpacing;



    explicit IntroMazePrefab(Position startingPosition)
            : topRow(placeTopRow(startingPosition)),
              leftColumn(placeLeftColumn(startingPosition)),
              bottomRow(placeBottomRow(startingPosition)),
              rightColumn(placeRightColumn(startingPosition)){
        createSkeleton(startingPosition);
        FourTreePrefab{startingPosition};
    }

    void createSkeleton(Position startingPosition) {
        createWalls(startingPosition);
        createLetters(startingPosition);
    }

    void createLetters(Position startingPosition) {
        const Position letterStartPosition = startingPosition + Position(70, 0);
        LetterStreamPrefab{letterStartPosition, 0, 32};
        LetterStreamPrefab{Window::deriveRelativeTopLeft(startingPosition) + Position((float)75, Window::getMiddlePosition().yPos), 0, 35, true};
        VerticalLetterStreamPrefab{Position(startingPosition.xPos + 10, static_cast<float>(Window::getTopYPosition(startingPosition.yPos))), 0, 15, true};
        VerticalLetterStreamPrefab{startingPosition + Position(10, 25), 0, 15};
    }

    void createWalls(Position startingPosition) {
        Position leftWallStartPosition = Window::deriveRelativeTopLeft(startingPosition) + Position(horizontalRowStartOffset, Window::getMiddlePosition().yPos + 25);
        HalfwayOpenWallRowPrefab bottomMiddleRow{leftWallStartPosition, innerHorizontalLengthInWalls};
        leftWallStartPosition += Position(0, -50);
        HalfwayOpenWallRowPrefab topMiddleRow{leftWallStartPosition, innerHorizontalLengthInWalls};

        HalfwayOpenWallColumnPrefab leftTopMiddleCol{Position(static_cast<int>(topMiddleRow.startOfIncision.xPos), Window::getTopYPosition(static_cast<int>(topMiddleRow.startOfIncision.yPos))), 7};

        HalfwayOpenWallColumnPrefab rightTopMiddleCol{Position(static_cast<int>(topMiddleRow.endOfIncision.xPos), Window::getTopYPosition(static_cast<int>(topMiddleRow.startOfIncision.yPos))), 7};

        HalfwayOpenWallColumnPrefab leftBottomMiddleCol{Position((topMiddleRow.startOfIncision.xPos), bottomMiddleRow.startOfIncision.yPos), 7};
        HalfwayOpenWallColumnPrefab rightBottomMiddleCol{Position((topMiddleRow.endOfIncision.xPos), bottomMiddleRow.endOfIncision.yPos), 7};
    }

private:
    static HalfwayOpenWallRowPrefab placeTopRow(Position startingPosition) {
        Position wallStartPosition = {Window::deriveRelativeTopLeft(startingPosition).xPos + horizontalRowStartOffset, Window::deriveRelativeTopLeft(startingPosition).yPos};
        return HalfwayOpenWallRowPrefab{wallStartPosition, outerHorizontalLengthInWalls};
    }

    static HalfwayOpenWallColumnPrefab placeLeftColumn(Position startingPosition) {
        Position wallStartPosition = Window::deriveRelativeTopLeft(startingPosition);
        return HalfwayOpenWallColumnPrefab{wallStartPosition, verticalLengthInWalls};
    }

    static HalfwayOpenWallRowPrefab placeBottomRow(Position startingPosition) {
        Position bottomLeft = Window::deriveRelativeBottomLeft(startingPosition);
        Position bottomWallVisibilityAdjustment = {
                (float)VerticalWallPrefab::getSize().width + horizontalRowStartOffset,
                BOTTOM_SPACING_MULTIPLIER * (float)HorizontalWallPrefab::getSize().height
        };
        Position newBottomLeft = bottomLeft + bottomWallVisibilityAdjustment;
        spdlog::info("new bottom left x: {}", bottomLeft.xPos);
        return HalfwayOpenWallRowPrefab{newBottomLeft, outerHorizontalLengthInWalls};
    }

    static HalfwayOpenWallColumnPrefab placeRightColumn(Position startingPosition) {
        Position topRight = Window::deriveRelativeTopRight(startingPosition);
        Position rightWallVisibilityAdjustment = {
                (float)(2 * VerticalWallPrefab::getSize().width), 0.0
        };
        Position newTopRight = topRight - rightWallVisibilityAdjustment;
        return HalfwayOpenWallColumnPrefab{newTopRight, verticalLengthInWalls};
    }
};



#endif //TEXTBASED_INTROMAZEPREFAB_H
