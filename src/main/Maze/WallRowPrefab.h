#ifndef TEXTBASED_WALLROWPREFAB_H
#define TEXTBASED_WALLROWPREFAB_H

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

extern std::unique_ptr<ECSManager> ecsManager;
extern std::unique_ptr<EventBus> eventBus;

std::string horizontalWallText = "wall";
std::string verticalWallText = "w\na\nl\nl";

using OnDeathFunction = std::function<void(void)>;

struct WallRowPrefab {
    explicit WallRowPrefab(Position position, int length) {
        auto wallSize = TextComponent(TextGenerator::getHorizontalWallText()).getSurfaceSize();
        for(int x=0; x<length; x++){
            auto currPosition = position + Position((float)(wallSize.width * x), (float)0);
            Entity wall = ecsManager->createEntity();
            ecsManager->addComponentToEntity<TextComponent>(wall, horizontalWallText);
            ecsManager->addComponentToEntity<PositionComponent>(wall, currPosition);
            ecsManager->addComponentToEntity<StyleComponent>(wall);
            ecsManager->addComponentToEntity<CollisionComponent>(wall);
            ecsManager->addComponentToEntity<LiveComponent>(wall);
        }
    }
};

#endif //TEXTBASED_WALLROWPREFAB_H
