#include "EmmaWoodhouseSystem.h"
#include "../EventSystem/EventBus.h"
#include "../TextCommands/CharacterSpendEvent.h"
#include "../HighLevel/ECSManager.h"
#include "../MainPlayer/MainPlayerAccessSystem.h"
#include "EmmaWoodhouseComponent.h"

extern std::unique_ptr<ECSManager> ecsManager;
extern std::unique_ptr<EventBus> eventBus;

EmmaWoodhouseSystem::EmmaWoodhouseSystem() {
    listenToEvents();
}

void EmmaWoodhouseSystem::listenToEvents() {
    eventBus->listenToEvent<CharacterDepositEvent>(this, &EmmaWoodhouseSystem::onDeposit);
}

void EmmaWoodhouseSystem::onDeposit(CharacterDepositEvent &event) {
    if(event.letter != Letter::QUESTION_MARK){
        return;
    }

    Entity mainPlayer = ecsManager->getSystem<MainPlayerAccessSystem>().getMainPlayer();
    if (!ecsManager->hasComponent<EmmaWoodhouseComponent>(mainPlayer)){
        return;
    }

    auto& textComponent = ecsManager->getComponentFromEntity<TextComponent>(mainPlayer);
    auto& emmaComponent = ecsManager->getComponentFromEntity<EmmaWoodhouseComponent>(mainPlayer);
    std::string nextText = emmaComponent.getNextState(textComponent.text);
    textComponent.text = nextText;
}