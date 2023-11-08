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
#include "HorizontalWallPrefab.h"
#include "VerticalWallPrefab.h"
#include "WallRowPrefab.h"
#include "WallColumnPrefab.h"

extern std::unique_ptr<ECSManager> ecsManager;

struct IntroMazePrefab {
    explicit IntroMazePrefab(Position startingPosition) {
        Position wallStartPosition{Window::deriveRelativeTopLeft(startingPosition)};

        int horizontalLengthInWalls = 40;
        WallRowPrefab topRow{wallStartPosition, horizontalLengthInWalls};
        int verticalLengthInWalls = 16;
        WallColumnPrefab leftColumn{wallStartPosition, verticalLengthInWalls};

        Position bottomLeft{Window::deriveRelativeBottomLeft(startingPosition)};
        Position bottomWallVisibilityAdjustment{(float)VerticalWallPrefab::getSize().width, -1*(float)HorizontalWallPrefab::getSize().height};
        Position newBottomLeft = bottomLeft + bottomWallVisibilityAdjustment;
        WallRowPrefab bottomRow{newBottomLeft, horizontalLengthInWalls};


        Position topRight{Window::deriveRelativeTopRight(startingPosition)};
        Position rightWallVisibilityAdjustment{(float)(2*(VerticalWallPrefab::getSize().width)), 0.0};
        WallColumnPrefab rightColumn{topRight - rightWallVisibilityAdjustment, verticalLengthInWalls};

    }
};


#endif //TEXTBASED_INTROMAZEPREFAB_H
