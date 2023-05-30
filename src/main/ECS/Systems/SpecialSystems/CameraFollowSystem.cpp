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

    if (isAboveScreen(relativePlayerYPos, (float) playerSizeOffset.height)){
        newCameraPosition.yPos -= (float)Window::windowHeight;
    }
    if (isBelowScreen(relativePlayerYPos, (float) playerSizeOffset.height)){
        newCameraPosition.yPos += (float)Window::windowHeight;
    }

    auto relativePlayerXPos = playerPosition.xPos - camera->getCameraPosition().xPos;
    if (this->isRightOfScreen(relativePlayerXPos, (float) playerSizeOffset.width)){
        newCameraPosition.xPos -= (float)Window::windowWidth;
    }
    if (this->isLeftOfScreen(relativePlayerXPos, (float) playerSizeOffset.height)){
        newCameraPosition.xPos += (float)Window::windowWidth;
    }

    camera->positionCamera(newCameraPosition);
    spdlog::debug("Camera moved to position {}, {}", newCameraPosition.xPos, newCameraPosition.yPos);
}

bool CameraFollowSystem::isAboveScreen(float relativePlayerYPos, float playerHeight) const {
    return (relativePlayerYPos + playerHeight) < 0;
}

bool CameraFollowSystem::isBelowScreen(float relativePlayerYPos, float playerHeight) {
    return (relativePlayerYPos - playerHeight) > (float)Window::windowHeight;
}

bool CameraFollowSystem::isRightOfScreen(float relativePlayerXPos, float playerWidth) {
    return (relativePlayerXPos + playerWidth) < 0;
}

bool CameraFollowSystem::isLeftOfScreen(float relativePlayerXPos, float playerWidth) {
    return (relativePlayerXPos - playerWidth) > (float)Window::windowWidth;
}

//    auto xPositionWithPlayerInMiddle = playerPosition.xPos - (float)Window::windowWidth/2;
//    newCameraPosition.xPos = xPositionWithPlayerInMiddle + (float)playerSizeOffset.width / 2;
//    auto yPositionWithPlayerInMiddle = playerPosition.yPos - (float)Window::windowHeight/2;
//    newCameraPosition.yPos = yPositionWithPlayerInMiddle;
//
//    camera->positionCamera(newCameraPosition);
