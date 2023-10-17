#ifndef TEXTBASED_ABYZPREFAB_H
#define TEXTBASED_ABYZPREFAB_H

#include <memory>
#include "../HighLevel/ECSManager.h"
#include "../PositionsAndMovement/CollisionComponent.h"
#include "../Creation/Item.h"
#include "../Creation/CreateItemAtEntityEvent.h"
#include "../Attacking/AttackableComponent.h"
#include "../Health/OnDeathComponent.h"
#include "../Health/HealthComponent.h"
#include "AbyzComponent.h"
#include "../PositionsAndMovement/LiveComponent.h"
#include "../PositionsAndMovement/PositionComponent.h"

extern std::unique_ptr<ECSManager> ecsManager;
extern std::unique_ptr<EventBus> eventBus;

struct AbyzPrefab{
    Entity abyz;
    explicit AbyzPrefab(Position position){
        abyz = ecsManager->createEntity();
        ecsManager->addComponentToEntity<TextComponent>(abyz, "Abyz");
        ecsManager->addComponentToEntity<PositionComponent>(abyz, position);
        ecsManager->addComponentToEntity<StyleComponent>(abyz, Type::PLAIN_TEXT);
        ecsManager->addComponentToEntity<LiveComponent>(abyz);
        ecsManager->addComponentToEntity<AbyzComponent>(abyz);
        ecsManager->addComponentToEntity<HealthComponent>(abyz, 5);
        ecsManager->addComponentToEntity<AttackableComponent>(abyz);

        int id = abyz.getId();
        ecsManager->addComponentToEntity<OnDeathComponent>(abyz, [this, id]() {
            eventBus->emitEvent<CreateItemAtEntityEvent>(Item::LETTER, Entity{id});
        });
        ecsManager->addComponentToEntity<CollisionComponent>(abyz);
    }
};

#endif //TEXTBASED_ABYZPREFAB_H
