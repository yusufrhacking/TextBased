#include "AbyzTargetingSystem.h"

#include "AbyzPrefab.h"
#include "AbyzTargetingComponent.h"
#include "PriorityTargetComponent.h"
#include "../PositionsAndMovement/LiveComponent.h"
#include "../PositionsAndMovement/PositionComponent.h"

extern std::unique_ptr<ECSManager> ecsManager;

AbyzTargetingSystem::AbyzTargetingSystem() {
    requireComponent<PriorityTargetComponent>();
    requireComponent<PositionComponent>();
    requireComponent<LiveComponent>();
    requireComponent<TextComponent>();
}

void AbyzTargetingSystem::update(double deltaTime) {
    for(auto target: getRelevantEntities()) {
        auto targetPosition = ecsManager->getComponentFromEntity<PositionComponent>(target).getPosition();


        Entity abyz = ecsManager->createEntity();
        ecsManager->addComponentToEntity<TextComponent>(abyz, "Abyz");
        ecsManager->addComponentToEntity<PositionComponent>(abyz, targetPosition + Position(0, 400));
        ecsManager->addComponentToEntity<LiveComponent>(abyz);
        ecsManager->addComponentToEntity<AbyzComponent>(abyz);
        ecsManager->addComponentToEntity<AbyzTargetingComponent>(abyz, AbyzTargetingComponent(target, targetPosition));

        ecsManager->removeComponentFromEntity<PriorityTargetComponent>(target);
    }
}
