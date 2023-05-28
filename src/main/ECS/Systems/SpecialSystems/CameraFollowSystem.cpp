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

    auto xPositionWithPlayerInMiddle = playerPosition.xPos - (float)Window::windowWidth/2;
    freshCameraPosition.xPos = xPositionWithPlayerInMiddle + (float)playerSizeOffset.width/2;
    auto yPositionWithPlayerInMiddle = playerPosition.yPos - (float)Window::windowHeight/2;
    freshCameraPosition.yPos = yPositionWithPlayerInMiddle;

    camera->positionCamera(freshCameraPosition);
    spdlog::trace("Camera moved to position {}, {}", freshCameraPosition.xPos, freshCameraPosition.yPos);
}
