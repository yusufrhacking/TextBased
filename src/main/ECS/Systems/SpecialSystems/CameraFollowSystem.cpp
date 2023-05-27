#include <spdlog/spdlog.h>
#include "CameraFollowSystem.h"
#include "../../Design/Managers/ECSManager.h"


extern std::unique_ptr<ECSManager> ecsManager;

CameraFollowSystem::CameraFollowSystem() {
    requireComponent<MainPlayerComponent>();
    requireComponent<TextComponent>();
    requireComponent<PositionComponent>();
}


void CameraFollowSystem::update() {
    if(getRelevantEntities().empty()){
        return;
    }
    auto entity = *getRelevantEntities().begin();
    auto playerPosition = ecsManager->getComponentFromEntity<PositionComponent>(entity).getPosition();

    auto playerSizeOffset = ecsManager->getComponentFromEntity<TextComponent>(entity).surfaceSize;

    auto freshCameraPosition = window->getCameraPosition();
    auto cameraWidth = Window::windowWidth;
    auto cameraHeight = Window::windowHeight;

    if (playerPosition.xPos + ((float)cameraWidth/2) < (float)Window::windowWidth){
        freshCameraPosition.xPos = playerPosition.xPos - (float)Window::windowWidth/2 + (float)playerSizeOffset.width/2;
    }
    if (playerPosition.yPos + ((float)cameraHeight/2) < (float)Window::windowHeight){
        freshCameraPosition.yPos = playerPosition.yPos - (float)Window::windowHeight/2;
    }

    window->positionCamera(freshCameraPosition);
    spdlog::trace("Camera moved to position {}, {}", freshCameraPosition.xPos, freshCameraPosition.yPos);
}
