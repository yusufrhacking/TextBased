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
    explicit IntroMazePrefab(Position startingPosition) {
        makeSkeleton(startingPosition);
    }

private:
    void makeSkeleton(Position startingPosition){
        Position wallStartPosition{Window::deriveRelativeTopLeft(startingPosition)};

        int horizontalLengthInWalls = 40;
        HalfwayOpenWallRowPrefab topRow{wallStartPosition, horizontalLengthInWalls};
        int verticalLengthInWalls = 15;
        HalfwayOpenWallColumnPrefab leftColumn{wallStartPosition, verticalLengthInWalls};

        Position bottomLeft{Window::deriveRelativeBottomLeft(startingPosition)};
        Position bottomWallVisibilityAdjustment{(float)VerticalWallPrefab::getSize().width, -3*(float)HorizontalWallPrefab::getSize().height};
        spdlog::info("Height: {}", HorizontalWallPrefab::getSize().height);
        Position newBottomLeft = bottomLeft + bottomWallVisibilityAdjustment;
        HalfwayOpenWallRowPrefab bottomRow{newBottomLeft, horizontalLengthInWalls};

        spdlog::info("Window Size: {}, {}", Window::windowWidth, Window::windowHeight);
        spdlog::info("BottomLeft: {}, {}", newBottomLeft.xPos, newBottomLeft.yPos);
        spdlog::info("Mod: {}, {}", (int)newBottomLeft.xPos % Window::windowWidth, (int)newBottomLeft.yPos % Window::windowHeight);

        Position topRight{Window::deriveRelativeTopRight(startingPosition)};
        Position rightWallVisibilityAdjustment{(float)(2*(VerticalWallPrefab::getSize().width)), 0.0};
        HalfwayOpenWallColumnPrefab rightColumn{topRight - rightWallVisibilityAdjustment, verticalLengthInWalls};
    }
};


#endif //TEXTBASED_INTROMAZEPREFAB_H
