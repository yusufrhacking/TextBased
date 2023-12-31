#include "AbyzRunningSystem.h"

#include "AbyzPrefab.h"
#include "AbyzTargetingComponent.h"
#include "TargetForAbyzComponent.h"
#include "../PositionsAndMovement/LiveComponent.h"
#include "../PositionsAndMovement/PositionComponent.h"

extern std::unique_ptr<ECSManager> ecsManager;

AbyzRunningSystem::AbyzRunningSystem() {
    requireComponent<TargetForAbyzComponent>();
    requireComponent<PositionComponent>();
    requireComponent<LiveComponent>();
    requireComponent<TextComponent>();
}

void AbyzRunningSystem::update(double deltaTime) {
    for(auto target: getRelevantEntities()) {
        auto targetPosition = ecsManager->getComponentFromEntity<PositionComponent>(target).getPosition();


        Entity abyz = ecsManager->createEntity();
        ecsManager->addComponentToEntity<TextComponent>(abyz, "Abyz");
        ecsManager->addComponentToEntity<PositionComponent>(abyz, targetPosition + Position(0, 400));
        ecsManager->addComponentToEntity<GenericStyleComponent>(abyz, Type::PLAIN_TEXT);
        ecsManager->addComponentToEntity<LiveComponent>(abyz);
        ecsManager->addComponentToEntity<AbyzComponent>(abyz);
        ecsManager->addComponentToEntity<AbyzTargetingComponent>(target, targetPosition);

        ecsManager->removeComponentFromEntity<TargetForAbyzComponent>(target);
    }
}
