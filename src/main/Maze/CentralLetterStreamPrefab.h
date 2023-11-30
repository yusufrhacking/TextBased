#ifndef CENTRALLETTERSTREAMPREFAB_H
#define CENTRALLETTERSTREAMPREFAB_H


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

struct CentralLetterStreamPrefab {
    CentralLetterStreamPrefab(Position startingPosition) {
        const Position letterStartPosition = startingPosition + Position(70, 0);
        LetterStreamPrefab{letterStartPosition, 0, 32};
        LetterStreamPrefab{Window::deriveRelativeTopLeft(startingPosition) + Position((float)75, Window::getMiddlePosition().yPos), 0, 35, true};
        VerticalLetterStreamPrefab{Position(startingPosition.xPos + 10, static_cast<float>(Window::getTopYPosition(startingPosition.yPos))), 0, 15, true};
        VerticalLetterStreamPrefab{startingPosition + Position(10, 25), 0, 15};
    }
};


#endif //CENTRALLETTERSTREAMPREFAB_H
