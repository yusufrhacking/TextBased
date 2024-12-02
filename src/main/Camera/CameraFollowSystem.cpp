#include <spdlog/spdlog.h>
#include "CameraFollowSystem.h"
#include "../HighLevel/ECSManager.h"
#include "../HighLevel/Game.h"
#include "../MainPlayer/MainPlayerComponent.h"
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

    auto newCameraPosition = getNewCameraPositionByPlatformCenter(previousCameraPosition, playerPosition, playerSizeOffset);
    spdlog::trace("Camera moved to position {}, {}", newCameraPosition.x, newCameraPosition.y);
    return Camera(newCameraPosition);
}

Position CameraFollowSystem::getNewCameraPositionByFrame(Position previousCameraPosition, const Position &playerPosition, const EntitySize &playerSizeOffset) {
    auto newCameraPosition = previousCameraPosition;
    auto relativePlayerYPos = playerPosition.y - previousCameraPosition.y;
    if (this->isAboveScreen(relativePlayerYPos, (float) playerSizeOffset.height)){
        newCameraPosition.y -= (float)Window::windowHeight;
    }
    if (this->isBelowScreen(relativePlayerYPos, (float) playerSizeOffset.height)){
        newCameraPosition.y += (float)Window::windowHeight;
    }

    auto relativePlayerXPos = playerPosition.x - previousCameraPosition.x;
    if (this->isRightOfScreen(relativePlayerXPos, (float) playerSizeOffset.width)){
        newCameraPosition.x -= (float)Window::windowWidth;
    }
    if (this->isLeftOfScreen(relativePlayerXPos, (float) playerSizeOffset.height)){
        newCameraPosition.x += (float)Window::windowWidth;
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

Position CameraFollowSystem::getNewCameraPositionByCentering(Position previousCameraPosition, const Position &playerPosition, const EntitySize &playerSizeOffset){
    auto newCameraPosition = previousCameraPosition;
    auto xPositionWithPlayerInMiddle = playerPosition.x - (float)Window::windowWidth/2;
    newCameraPosition.x = xPositionWithPlayerInMiddle + (float)playerSizeOffset.width / 2;
    auto yPositionWithPlayerInMiddle = playerPosition.y - (float)Window::windowHeight/2;
    newCameraPosition.y = yPositionWithPlayerInMiddle;

    return newCameraPosition;
}

Position CameraFollowSystem::getNewCameraPositionByPlatformFollow(Position previousCameraPosition, const Position &playerPosition, const EntitySize &playerSizeOffset){
    auto newCameraPosition = previousCameraPosition;
    auto xPositionWithPlayerInMiddle = playerPosition.x - (float)Window::windowWidth/8;
    newCameraPosition.x = xPositionWithPlayerInMiddle + (float)playerSizeOffset.width / 2;
    auto yPositionWithPlayerInMiddle = playerPosition.y - (float)Window::windowHeight/2 - (float)Window::windowHeight/4;
    newCameraPosition.y = yPositionWithPlayerInMiddle;

    return newCameraPosition;
}

Position CameraFollowSystem::getNewCameraPositionByPlatformCenter(Position previousCameraPosition, const Position &playerPosition, const EntitySize &playerSizeOffset){
    auto newCameraPosition = previousCameraPosition;
    auto xPositionWithPlayerInMiddle = playerPosition.x - (float)Window::windowWidth/2;
    newCameraPosition.x = xPositionWithPlayerInMiddle + (float)playerSizeOffset.width / 2;
    auto yPositionWithPlayerInMiddle = playerPosition.y - (float)Window::windowHeight/2 - (float)Window::windowHeight/4;
    newCameraPosition.y = yPositionWithPlayerInMiddle;

    return newCameraPosition;
}

