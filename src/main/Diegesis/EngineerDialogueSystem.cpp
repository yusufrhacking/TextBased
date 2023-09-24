#include "EngineerDialogueSystem.h"
#include "../EventSystem/EventBus.h"
#include "EngineerTerminalEvent.h"
#include <memory>

extern std::unique_ptr<EventBus> eventBus;

EngineerDialogueSystem::EngineerDialogueSystem() {
    listenToEvents();
}

void EngineerDialogueSystem::listenToEvents() {
    eventBus->listenToEvent<CharacterDepositEvent>(this, &EngineerDialogueSystem::onLetter);
    eventBus->listenToEvent<CreatePlayerItemEvent>(this, &EngineerDialogueSystem::onCreateAxe);
    eventBus->listenToEvent<CreateItemAtPositionEvent>(this, &EngineerDialogueSystem::onWoodSpawn);
    eventBus->listenToEvent<PlayerPickUpEvent>(this, &EngineerDialogueSystem::onPickup);
    eventBus->listenToEvent<PlaceEvent>(this, &EngineerDialogueSystem::onPlace);
}

void EngineerDialogueSystem::onLetter(CharacterDepositEvent &event) {
    if (isFirstLetter){
        isFirstLetter = false;
        eventBus->emitEvent<EngineerTerminalEvent>("Try 'create axe'");
    }
}


void EngineerDialogueSystem::onCreateAxe(CreatePlayerItemEvent &event) {
    eventBus->emitEvent<EngineerTerminalEvent>("Try 'chop'");
}

void EngineerDialogueSystem::onWoodSpawn(CreateItemAtPositionEvent &event) {
    eventBus->emitEvent<EngineerTerminalEvent>("Try 'pickup'");
}

void EngineerDialogueSystem::onPickup(PlayerPickUpEvent &event) {
    eventBus->emitEvent<EngineerTerminalEvent>("Try 'place wood'");
}

void EngineerDialogueSystem::onPlace(PlaceEvent &event) {
    eventBus->emitEvent<EngineerTerminalEvent>("Try 'stash axe'");
}
