#include <spdlog/spdlog.h>
#include "CameraFollowSystem.h"
#include "../HighLevel/ECSManager.h"
#include "../HighLevel/Game.h"
#include "../PositionsAndMovement/PositionComponent.h"

extern std::unique_ptr<ECSManager> ecsManager;

CameraFollowSystem::CameraFollowSystem() {
    requireComponent<MainPlayerComponent>();
    requireComponent<TextComponent>();
    requireComponent<PositionComponent>();
}


Camera CameraFollowSystem::updateCameraPosition(Position previousCameraPosition) {
    if(getRelevantEntities().empty()){
        return Camera(previousCameraPosition);
    }
    auto entity = *getRelevantEntities().begin();
    auto playerPosition = ecsManager->getComponentFromEntity<PositionComponent>(entity).getPosition();
    auto playerSizeOffset = ecsManager->getComponentFromEntity<TextComponent>(entity).getSurfaceSize();

    auto newCameraPosition = getNewCameraPositionByFrame(previousCameraPosition, playerPosition, playerSizeOffset);
    spdlog::trace("Camera moved to position {}, {}", newCameraPosition.xPos, newCameraPosition.yPos);
    return Camera(newCameraPosition);
}

Position CameraFollowSystem::getNewCameraPositionByFrame(Position previousCameraPosition, const Position &playerPosition, const Size &playerSizeOffset) {
    auto newCameraPosition = previousCameraPosition;
    auto relativePlayerYPos = playerPosition.yPos - previousCameraPosition.yPos;
    if (this->isAboveScreen(relativePlayerYPos, (float) playerSizeOffset.height)){
        newCameraPosition.yPos -= (float)Window::windowHeight;
    }
    if (this->isBelowScreen(relativePlayerYPos, (float) playerSizeOffset.height)){
        newCameraPosition.yPos += (float)Window::windowHeight;
    }

    auto relativePlayerXPos = playerPosition.xPos - previousCameraPosition.xPos;
    if (this->isRightOfScreen(relativePlayerXPos, (float) playerSizeOffset.width)){
        newCameraPosition.xPos -= (float)Window::windowWidth;
    }
    if (this->isLeftOfScreen(relativePlayerXPos, (float) playerSizeOffset.height)){
        newCameraPosition.xPos += (float)Window::windowWidth;
    }
    return newCameraPosition;
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

Position CameraFollowSystem::getNewCameraPositionByCentering(Position previousCameraPosition, const Position &playerPosition, const Size &playerSizeOffset){
    auto newCameraPosition = previousCameraPosition;
    auto xPositionWithPlayerInMiddle = playerPosition.xPos - (float)Window::windowWidth/2;
    newCameraPosition.xPos = xPositionWithPlayerInMiddle + (float)playerSizeOffset.width / 2;
    auto yPositionWithPlayerInMiddle = playerPosition.yPos - (float)Window::windowHeight/2;
    newCameraPosition.yPos = yPositionWithPlayerInMiddle;

    return newCameraPosition;
}

