#include "PendingDeathSystem.h"
#include "PendingDeathComponent.h"
#include "../HighLevel/ECSManager.h"
#include "OnDeathComponent.h"

extern std::unique_ptr<ECSManager> ecsManager;

PendingDeathSystem::PendingDeathSystem() {
    requireComponent<PendingDeathComponent>();
}

void PendingDeathSystem::update(double deltaTime) {
    for (auto entity: getRelevantEntities()){
        if (ecsManager->hasComponent<OnDeathComponent>(entity)){
            auto& onDeathComponent = ecsManager->getComponentFromEntity<OnDeathComponent>(entity);
            onDeathComponent.emitEvent();
        }
        ecsManager->killEntity(entity);
    }
}
