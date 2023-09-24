#include "EngineerDialogueSystem.h"
#include "../EventSystem/EventBus.h"
#include "../TextInput/TextCommandEvent.h"
#include "EngineerTerminalEvent.h"
#include <memory>

extern std::unique_ptr<EventBus> eventBus;

EngineerDialogueSystem::EngineerDialogueSystem() {
    listenToEvents();
}

void EngineerDialogueSystem::listenToEvents() {
    eventBus->listenToEvent<CharacterDepositEvent>(this, &EngineerDialogueSystem::onLetter);
}

void EngineerDialogueSystem::onLetter(CharacterDepositEvent &event) {
    if (isFirstLetter){
        isFirstLetter = false;
        eventBus->emitEvent<EngineerTerminalEvent>("The Engineer is Here.");
    }
}
