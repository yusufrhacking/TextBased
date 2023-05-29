#include <spdlog/spdlog.h>
#include "MapGenerationSystem.h"
#include "../../Components/MainPlayerComponent.h"
#include "../../Components/PositionComponent.h"
#include "../../Design/Managers/ECSManager.h"
#include "../../../Game/GameSystems/Camera/Camera.h"
#include "../../../Game/Levels/ForestFrame.h"

extern std::unique_ptr<ECSManager> ecsManager;
extern std::unique_ptr<Camera> camera;

MapGenerationSystem::MapGenerationSystem() {
    relativeCameraPosition = camera->getCameraPosition();
}

void MapGenerationSystem::update() {
    if(currFrame > 0){
        ForestFrame(camera->getCameraPosition());
    }
}
