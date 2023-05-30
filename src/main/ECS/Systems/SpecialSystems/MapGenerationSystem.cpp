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
    //Idea, when I get to the middle of the frame, I need to fill in the 8 frames around me
    //Do this forever
    //To do this, I will need a map object that can check if frames are "generated"
    //And then also;
    if(currFrame > 0 && !doneBefore){
        spdlog::debug("Forest Frame inputted");
        ForestFrame(camera->getCameraPosition());
        doneBefore = true;
    }
}
