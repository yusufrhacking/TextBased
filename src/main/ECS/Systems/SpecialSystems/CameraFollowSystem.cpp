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

    auto newCameraPosition = camera->getCameraPosition();

    auto relativePlayerYPos = playerPosition.yPos - camera->getCameraPosition().yPos;
    spdlog::info("Player Pos y {}", playerPosition.yPos);
    spdlog::info("Camera pos y {}", camera->getCameraPosition().yPos);
    if (isOutsideTopOfScreen(relativePlayerYPos, (float)playerSizeOffset.height)){
        newCameraPosition.yPos -= (float)Window::windowHeight;
        spdlog::info("Lesser CAMERA");
    }
    if (isOutsideBottomOfScreen(relativePlayerYPos, (float)playerSizeOffset.height)){
        newCameraPosition.yPos += (float)Window::windowHeight;
        spdlog::info("GREATER CAMERA");
    }

    camera->positionCamera(newCameraPosition);

//
//    auto playerSizeOffset = ecsManager->getComponentFromEntity<TextComponent>(entity).surfaceSize;
//
//
//    auto xPositionWithPlayerInMiddle = playerPosition.xPos - (float)Window::windowWidth/2;
//    newCameraPosition.xPos = xPositionWithPlayerInMiddle + (float)playerSizeOffset.width / 2;
//    auto yPositionWithPlayerInMiddle = playerPosition.yPos - (float)Window::windowHeight/2;
//    newCameraPosition.yPos = yPositionWithPlayerInMiddle;
//
//    camera->positionCamera(newCameraPosition);
//    spdlog::trace("Camera moved to position {}, {}", newCameraPosition.xPos, newCameraPosition.yPos);
}

bool CameraFollowSystem::isOutsideTopOfScreen(float relativePlayerYPos, float playerHeight) const {
    return (relativePlayerYPos + playerHeight) < 0;
}

bool CameraFollowSystem::isOutsideBottomOfScreen(float relativePlayerYPos, float playerHeight) {
    return (relativePlayerYPos - playerHeight) > (float)Window::windowHeight;
}
