#include "CameraFollowSystem.h"
#include "../../Design/Managers/ECSManager.h"


extern std::unique_ptr<ECSManager> ecsManager;

CameraFollowSystem::CameraFollowSystem() {
    requireComponent<MainPlayerComponent>();
    requireComponent<TextComponent>();
    requireComponent<PositionComponent>();
}


void CameraFollowSystem::update(double deltaTime) {
    auto entity = *getRelevantEntities().begin();
    auto playerPosition = ecsManager->getComponentFromEntity<PositionComponent>(entity).getPosition();

    auto playerSizeOffset = ecsManager->getComponentFromEntity<TextComponent>(entity).surfaceSize;

    auto freshCameraPosition = window->getCameraPosition();
    auto cameraWidth = window->getWindowWidth();
    auto cameraHeight = window->getWindowHeight();

    if (playerPosition.xPos + ((float)cameraWidth/2) < (float)window->getWindowWidth()){
        freshCameraPosition.xPos = playerPosition.xPos - (float)window->getWindowWidth()/2 + (float)playerSizeOffset.width/2;
    }
    if (playerPosition.yPos + ((float)cameraHeight/2) < (float)window->getWindowHeight()){
        freshCameraPosition.yPos = playerPosition.yPos - (float)window->getWindowHeight()/2;
    }

    window->positionCamera(freshCameraPosition);

}
