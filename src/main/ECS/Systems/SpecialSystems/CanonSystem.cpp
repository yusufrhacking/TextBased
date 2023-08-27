#include "CanonSystem.h"
#include "../../Components/PositionComponent.h"
#include "../../Design/Managers/ECSManager.h"

extern std::unique_ptr<ECSManager> ecsManager;

CanonSystem::CanonSystem(Canon &canon) : canon(canon) {
    requireComponent<PositionComponent>();
    for (auto entity : getRelevantEntities()){
        auto mapPosition = ecsManager->getComponentFromEntity<PositionComponent>(entity).getMapPosition();
        canon.placeEntity(entity, mapPosition);
    }
}
