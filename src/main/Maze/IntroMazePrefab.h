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
#include "WallRowPrefab.h"
#include "WallColumnPrefab.h"

extern std::unique_ptr<ECSManager> ecsManager;

struct IntroMazePrefab {
    explicit IntroMazePrefab(Position startingPosition) {
        Position wallStartPosition{Window::deriveRelativeTopLeft(startingPosition)};

        int horizontalLengthInWalls = 45;
        WallRowPrefab wallRow{wallStartPosition, horizontalLengthInWalls};


        WallColumnPrefab wallColumn{wallStartPosition, 15};
    }
};


#endif //TEXTBASED_INTROMAZEPREFAB_H
