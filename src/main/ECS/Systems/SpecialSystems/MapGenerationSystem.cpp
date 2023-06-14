#include <spdlog/spdlog.h>
#include "MapGenerationSystem.h"
#include "../../Components/MainPlayerComponent.h"
#include "../../Components/PositionComponent.h"
#include "../../Design/Managers/ECSManager.h"
#include "../../../Game/GameSystems/Camera/Camera.h"
#include "../../../Game/Levels/Forest/ForestFrame.h"

extern std::unique_ptr<ECSManager> ecsManager;
extern std::unique_ptr<Camera> camera;

MapGenerationSystem::MapGenerationSystem(std::shared_ptr<FrameMap> frameMap) {
    this->frameMap = frameMap;
    requireComponent<PositionComponent>();
    requireComponent<MainPlayerComponent>();
}

void MapGenerationSystem::update() {
    if (getRelevantEntities().empty()){
        return;
    }
    Entity entity = *getRelevantEntities().begin();
    auto playerPosition = ecsManager->getComponentFromEntity<PositionComponent>(entity).getPosition();

    frameMap->surroundLocation(playerPosition);
}
