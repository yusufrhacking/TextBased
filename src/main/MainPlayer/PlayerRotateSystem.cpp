#include "PlayerRotateSystem.h"
#include "../EventSystem/EventBus.h"
#include "../HighLevel/ECSManager.h"
#include "MainPlayerAccessSystem.h"
#include "RotateComponent.h"
#include "RotateEvent.h"

extern std::unique_ptr<ECSManager> ecsManager;
extern std::unique_ptr<EventBus> eventBus;


PlayerRotateSystem::PlayerRotateSystem() {
    listenToEvents();
}

void PlayerRotateSystem::listenToEvents() {
    eventBus->listenToEvent<RotateEvent>(this, &PlayerRotateSystem::onRotate);
}

void PlayerRotateSystem::onRotate(RotateEvent &event) {
    auto mainPlayer = ecsManager->getSystem<MainPlayerAccessSystem>().getMainPlayer();
    if (ecsManager->hasComponent<RotationComponent>(mainPlayer)){
        std::string& text = ecsManager->getComponentFromEntity<TextComponent>(mainPlayer).text;
        ecsManager->getComponentFromEntity<RotationComponent>(mainPlayer).rotate(text);
    }
}
