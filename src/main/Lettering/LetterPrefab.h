#ifndef TEXTBASED_LETTERPREFAB_H
#define TEXTBASED_LETTERPREFAB_H

#include <memory>
#include "../HighLevel/ECSManager.h"
#include "../PositionsAndMovement/CollisionComponent.h"
#include "../Creation/Item.h"
#include "../Creation/CreateItemAtEntityEvent.h"
#include "../Attacking/AttackableComponent.h"
#include "../Health/OnDeathComponent.h"
#include "../Health/HealthComponent.h"
#include "../PositionsAndMovement/LiveComponent.h"
#include "../PositionsAndMovement/PositionComponent.h"
#include "LetterComponent.h"

extern std::unique_ptr<ECSManager> ecsManager;
extern std::unique_ptr<EventBus> eventBus;

struct LetterPrefab{
    Entity entity;
    LetterPrefab(char letter, Position position){
        entity = ecsManager->createEntity();
        ecsManager->addComponentToEntity<TextComponent>(entity, std::string(1, letter));
        ecsManager->addComponentToEntity<PositionComponent>(entity, position);
        ecsManager->addComponentToEntity<StyleComponent>(entity, Type::PLAIN_LETTER);
        ecsManager->addComponentToEntity<LiveComponent>(entity);
        ecsManager->addComponentToEntity<LetterComponent>(entity, char_to_enum(letter));
    }
};

#endif //TEXTBASED_LETTERPREFAB_H
