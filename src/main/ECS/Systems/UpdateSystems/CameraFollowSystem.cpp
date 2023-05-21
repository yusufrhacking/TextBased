#include "CameraFollowSystem.h"
#include "../../Design/Managers/ECSManager.h"

extern std::unique_ptr<Window> window;
extern std::unique_ptr<ECSManager> ecsManager;

CameraFollowSystem::CameraFollowSystem() {
    requireComponent<MainPlayerComponent>();
    requireComponent<PositionComponent>();
}


void CameraFollowSystem::update(double deltaTime) {
    for (Entity entity: getRelevantEntities()){
        auto& position = ecsManager->getComponentFromEntity<PositionComponent>(entity);
        window->positionCamera(*position.position);
    }
}
