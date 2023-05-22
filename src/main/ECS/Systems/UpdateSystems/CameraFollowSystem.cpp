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
        auto& playerPosition = ecsManager->getComponentFromEntity<PositionComponent>(entity).position;
        auto freshCameraPosition = window->getCameraPosition();
        auto cameraWidth = window->getWindowWidth();
        auto cameraHeight = window->getWindowHeight();

        if (playerPosition->xPos + ((float)cameraWidth/2) < (float)window->getWindowWidth()){
            freshCameraPosition.xPos = playerPosition->xPos - (float)window->getWindowWidth()/2;
        }
        if (playerPosition->yPos + ((float)cameraHeight/2) < (float)window->getWindowHeight()){
            freshCameraPosition.yPos = playerPosition->yPos - (float)window->getWindowHeight()/2;
        }

        window->positionCamera(freshCameraPosition);
    }
}
