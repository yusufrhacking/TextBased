#include "UIControllerSystem.h"


#include <spdlog/spdlog.h>

#include "HideLetterBankEvent.h"
#include "../EventSystem/EventBus.h"
#include "../TextCommands/CharacterSpendEvent.h"
#include "../TextInput/TextCommandEvent.h"
#include "HideUIEvent.h"
#include "../HighLevel/ECSManager.h"

extern std::unique_ptr<ECSManager> ecsManager;
extern std::unique_ptr<EventBus> eventBus;

UIControllerSystem::UIControllerSystem() {
    listenToEvents();
}

void UIControllerSystem::listenToEvents() {
    eventBus->listenToEvent<HideUIEvent>(this, &UIControllerSystem::onUIEvent);
}

void UIControllerSystem::onUIEvent(HideUIEvent& event) {
    if(event.toHide == "letterbank") {
        eventBus->emitEvent<HideLetterBankEvent>();
    }
}



