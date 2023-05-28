#include <spdlog/spdlog.h>
#include "CameraFollowSystem.h"
#include "../../Design/Managers/ECSManager.h"
#include "../../../Game/GameSystems/Camera/Camera.h"
#include "../../../Game/Game.h"

extern std::unique_ptr<ECSManager> ecsManager;
extern std::unique_ptr<Camera> camera;

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

    auto freshCameraPosition = camera->getCameraPosition();
    auto cameraWidth = Window::windowWidth;
    auto cameraHeight = Window::windowHeight;

    auto relativeXPosition = playerPosition.xPos - Game::startingPosition.xPos;
    auto relativeYPosition = playerPosition.yPos - Game::startingPosition.yPos;

    if (relativeXPosition + ((float)cameraWidth/2) < (float)Window::windowWidth){
        freshCameraPosition.xPos = playerPosition.xPos - (float)Window::windowWidth/2 + (float)playerSizeOffset.width/2;
    }
    if (relativeYPosition + ((float)cameraHeight/2) < (float)Window::windowHeight){
        freshCameraPosition.yPos = playerPosition.yPos - (float)Window::windowHeight/2;
    }

    camera->positionCamera(freshCameraPosition);
    spdlog::trace("Camera moved to position {}, {}", freshCameraPosition.xPos, freshCameraPosition.yPos);
}
