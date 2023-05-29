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
    doneBefore = false;
}

void MapGenerationSystem::update() {
    if(currFrame > 100 && !doneBefore){
        spdlog::debug("Forest Frame inputted");
        ForestFrame(camera->getCameraPosition());
        doneBefore = true;
    }
}
