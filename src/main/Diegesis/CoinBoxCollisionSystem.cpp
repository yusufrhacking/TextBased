#include "CoinBoxCollisionSystem.h"

#include "../HighLevel/ECSManager.h"
#include "../MainPlayer/DamageEvent.h"
#include "../MainPlayer/MainPlayerComponent.h"
#include "../Emma/CoinBoxComponent.h"
#include "../PositionsAndMovement/PositionComponent.h"
#include "../PositionsAndMovement/LiveComponent.h"
#include "../Lettering/LetterComponent.h"

extern std::unique_ptr<ECSManager> ecsManager;
extern std::unique_ptr<EventBus> eventBus;

CoinBoxCollisionSystem::CoinBoxCollisionSystem() {
    listenToEvents();
}

void CoinBoxCollisionSystem::listenToEvents() {
    eventBus->listenToEvent<TopBottomCollisionEvent>(this, &CoinBoxCollisionSystem::onTopBottomCollision);
}

void CoinBoxCollisionSystem::onTopBottomCollision(TopBottomCollisionEvent &event) {
    if (ecsManager->hasComponent<CoinBoxComponent>(event.top)) {
        if(ecsManager->hasComponent<MainPlayerComponent>(event.bottom)) {
            createCoin(event.top);
        }
    }
}

void CoinBoxCollisionSystem::createCoin(Entity boxEntity) {
    Position letterPosition = ecsManager->getComponentFromEntity<PositionComponent>(boxEntity).getPosition();
    auto size = ecsManager->getComponentFromEntity<TextComponent>(boxEntity).getSurfaceSize();
    letterPosition.x += size.width/2;
    letterPosition.y -= MONACO_HEIGHT_OF_A_LINE_OF_TEXT;

    Entity letterEntity = ecsManager->createEntity();
    char character = '?';

    ecsManager->addComponentToEntity<TextComponent>(letterEntity, std::string(1, character));
    ecsManager->addComponentToEntity<PositionComponent>(letterEntity, letterPosition);
    ecsManager->addComponentToEntity<GenericStyleComponent>(letterEntity, RenderStyle::GREEN_TERMINAL);
    ecsManager->addComponentToEntity<LiveComponent>(letterEntity);
    ecsManager->addComponentToEntity<LetterComponent>(letterEntity, char_to_enum(character));
    // add the rest
}
