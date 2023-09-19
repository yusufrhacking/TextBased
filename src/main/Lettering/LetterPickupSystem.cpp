#include "LetterPickupSystem.h"
#include "LetterComponent.h"
#include "../PositionsAndMovement/PositionComponent.h"
#include "../PositionsAndMovement/LiveComponent.h"
#include "../HighLevel/ECSManager.h"
#include "../MainPlayer/MainPlayerAccessSystem.h"
#include "../PositionsAndMovement/DistanceCalculator.h"

extern std::unique_ptr<ECSManager> ecsManager;

LetterPickupSystem::LetterPickupSystem() {
    requireComponent<PositionComponent>();
    requireComponent<LetterComponent>();
    requireComponent<LiveComponent>();
}

void LetterPickupSystem::update(double deltaTime) {
    auto mainPlayer = ecsManager->getSystem<MainPlayerAccessSystem>().getMainPlayer();
    auto mainPlayerPosition = ecsManager->getComponentFromEntity<PositionComponent>(mainPlayer).getPosition();
    auto mainPlayerSurfaceSize = ecsManager->getComponentFromEntity<TextComponent>(mainPlayer).getSurfaceSize();
    for (auto entity: getRelevantEntities()){
        auto letterPosition = ecsManager->getComponentFromEntity<PositionComponent>(entity).getPosition();
        auto surfaceSize = ecsManager->getComponentFromEntity<TextComponent>(entity).getSurfaceSize();
        bool isInRange = DistanceCalculator::isInAllowedRange(mainPlayerPosition, letterPosition,
                                                              mainPlayerSurfaceSize, surfaceSize, 5);
        if (isInRange){
            spdlog::debug("Pickupable Letter");
            //PICKUP
        }

    }
}


