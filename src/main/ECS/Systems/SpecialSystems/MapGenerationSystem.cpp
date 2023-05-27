#include <spdlog/spdlog.h>
#include "MapGenerationSystem.h"
#include "../../Components/MainPlayerComponent.h"
#include "../../Components/PositionComponent.h"
#include "../../Design/Managers/ECSManager.h"

extern std::unique_ptr<ECSManager> ecsManager;

MapGenerationSystem::MapGenerationSystem() {
    relativeCameraPosition = window->getCameraPosition();
}

void MapGenerationSystem::update() {
    auto const currentCameraPosition = window->getCameraPosition();

    auto unusedCameraWidth = currentCameraPosition.xPos - relativeCameraPosition.xPos;
    auto unusedCameraHeight = currentCameraPosition.yPos - relativeCameraPosition.yPos;

//    spdlog::info("free camera width, height {}, {}", unusedCameraWidth, unusedCameraHeight);
    auto cameraDifference = currentCameraPosition.getAbsoluteDifference(relativeCameraPosition);

}
