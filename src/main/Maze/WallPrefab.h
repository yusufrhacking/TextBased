#ifndef TEXTBASED_WALLPREFAB_H
#define TEXTBASED_WALLPREFAB_H
#include <memory>
#include "../HighLevel/ECSManager.h"
#include "../Creation/Item.h"
#include "../Creation/CreateItemAtPositionEvent.h"
#include "../Health/OnDeathComponent.h"
#include "../PositionsAndMovement/CollisionComponent.h"
#include "../PositionsAndMovement/LiveComponent.h"
#include "../PositionsAndMovement/PositionComponent.h"
#include "../Creation/CreateLetterAtPositionEvent.h"

extern std::unique_ptr<ECSManager> ecsManager;
extern std::unique_ptr<EventBus> eventBus;

std::string horizontalWallText = "wall";
std::string verticalWallText = "w\na\nl\nl";

using OnDeathFunction = std::function<void(void)>;

struct WallPrefab {
    Entity wall;

    explicit WallPrefab(Position position) {
        wall = ecsManager->createEntity();
        ecsManager->addComponentToEntity<TextComponent>(wall, horizontalWallText);
        ecsManager->addComponentToEntity<PositionComponent>(wall, position);
        ecsManager->addComponentToEntity<StyleComponent>(wall);
        ecsManager->addComponentToEntity<CollisionComponent>(wall);
        ecsManager->addComponentToEntity<LiveComponent>(wall);
    }
};

#endif //TEXTBASED_WALLPREFAB_H
