#include "UIControllerSystem.h"


#include <spdlog/spdlog.h>

#include "HideHealthBarEvent.h"
#include "HideLetterBankEvent.h"
#include "../EventSystem/EventBus.h"
#include "../TextCommands/CharacterSpendEvent.h"
#include "../TextInput/TextCommandEvent.h"
#include "HideUIEvent.h"
#include "ShowLetterBankEvent.h"
#include "ShowUIEvent.h"
#include "../HighLevel/ECSManager.h"
#include "ShowHealthBarEvent.h"

extern std::unique_ptr<ECSManager> ecsManager;
extern std::unique_ptr<EventBus> eventBus;

UIControllerSystem::UIControllerSystem() {
    listenToEvents();
}

void UIControllerSystem::listenToEvents() {
    eventBus->listenToEvent<HideUIEvent>(this, &UIControllerSystem::onHideEvent);
    eventBus->listenToEvent<ShowUIEvent>(this, &UIControllerSystem::onShowEvent);
}

void UIControllerSystem::onShowEvent(ShowUIEvent& event) {
    if(event.toShow == "letterbank") {
        eventBus->emitEvent<ShowLetterBankEvent>();
    } else if (event.toShow == "healthbar") {
        eventBus->emitEvent<ShowHealthBarEvent>();
    }
}

void UIControllerSystem::onHideEvent(HideUIEvent& event) {
    if(event.toHide == "letterbank") {
        eventBus->emitEvent<HideLetterBankEvent>();
    } else if (event.toHide == "healthbar") {
        eventBus->emitEvent<HideHealthBarEvent>();
    }
}



