#include "LetterPickupSystem.h"
#include "CharacterDepositEvent.h"
#include "LetterComponent.h"
#include "../PositionsAndMovement/PositionComponent.h"
#include "../PositionsAndMovement/LiveComponent.h"
#include "../HighLevel/ECSManager.h"
#include "../MainPlayer/MainPlayerAccessSystem.h"
#include "../PositionsAndMovement/DistanceCalculator.h"
#include "../Inventory/InventoryPickupComponent.h"

extern std::unique_ptr<ECSManager> ecsManager;
extern std::unique_ptr<EventBus> eventBus;

LetterPickupSystem::LetterPickupSystem() {
    requireComponent<PositionComponent>();
    requireComponent<LetterComponent>();
    requireComponent<LiveComponent>();
}

void LetterPickupSystem::update(double deltaTime) {
    if (!ecsManager->getSystem<MainPlayerAccessSystem>().hasMainPlayer()){
        return;
    }
    auto mainPlayer = ecsManager->getSystem<MainPlayerAccessSystem>().getMainPlayer();
    auto mainPlayerPosition = ecsManager->getComponentFromEntity<PositionComponent>(mainPlayer).getPosition();
    auto mainPlayerSurfaceSize = ecsManager->getComponentFromEntity<TextComponent>(mainPlayer).getSurfaceSize();



    for (auto entity: getRelevantEntities()){
        auto letterPosition = ecsManager->getComponentFromEntity<PositionComponent>(entity).getPosition();
        auto surfaceSize = ecsManager->getComponentFromEntity<TextComponent>(entity).getSurfaceSize();
        bool isInRange = DistanceCalculator::isInAllowedRange(mainPlayerPosition, letterPosition,
                                                              mainPlayerSurfaceSize, surfaceSize, 5);
        if (isInRange){
            auto letter = ecsManager->getComponentFromEntity<LetterComponent>(entity).character;
            spdlog::trace("Entity with let ter {} was picked up", enum_to_char(ecsManager->getComponentFromEntity<LetterComponent>(entity).character));
            eventBus->emitEvent<CharacterDepositEvent>(letter);
            ecsManager->killEntity(entity);
        }

    }
}


