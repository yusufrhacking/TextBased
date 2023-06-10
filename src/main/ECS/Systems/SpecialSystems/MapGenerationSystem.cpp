#include <spdlog/spdlog.h>
#include "MapGenerationSystem.h"
#include "../../Components/MainPlayerComponent.h"
#include "../../Components/PositionComponent.h"
#include "../../Design/Managers/ECSManager.h"
#include "../../../Game/GameSystems/Camera/Camera.h"
#include "../../../Game/Levels/ForestFrame.h"

extern std::unique_ptr<ECSManager> ecsManager;
extern std::unique_ptr<Camera> camera;

MapGenerationSystem::MapGenerationSystem(std::shared_ptr<FrameMap> frameMap) {
    this->frameMap = frameMap;
    requireComponent<PositionComponent>();
    requireComponent<MainPlayerComponent>();

    Entity entity = *getRelevantEntities().begin();
    auto playerPosition = ecsManager->getComponentFromEntity<PositionComponent>(entity).getPosition();
    frameMap->surroundLocation(playerPosition);
}

void MapGenerationSystem::update() {
    if (getRelevantEntities().empty()){
        return;
    }
    Entity entity = *getRelevantEntities().begin();
    auto playerPosition = ecsManager->getComponentFromEntity<PositionComponent>(entity).getPosition();

//    frameMap->surroundLocation(playerPosition);

    //Idea, when I get to the middle of the frame, I need to fill in the 8 frames around me
    //Do this forever
    //To do this, I will need a map object that can check if frames are "generated"
    //And then also;
//    if(currFrame > 0 && !doneBefore){
//        spdlog::debug("Forest Frame inputted");
//        ForestFrame give_me_a_name(camera->getCameraPosition());
//        doneBefore = true;
//    }
}
