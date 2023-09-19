#include <spdlog/spdlog.h>
#include "CharacterStorageSystem.h"
#include "Alphabet.h"
#include "../EventSystem/EventBus.h"
#include "../TextCommands/CharacterStorageEvent.h"
#include "../TextInput/ProspectiveTextCommandEvent.h"

extern std::unique_ptr<EventBus> eventBus;

CharacterStorageSystem::CharacterStorageSystem() {
    listenToEvents();
}

void CharacterStorageSystem::onSpend(CharacterStorageEvent& event){
    spdlog::debug("on spend");
    bool result = tryToSpendText(event.subject);
    if (result){
        eventBus->emitEvent<ProspectiveTextCommandEvent>(event.command, event.subject);
    }
}

bool CharacterStorageSystem::tryToSpendText(const std::string& text) {
    if (!isLegalSpend(text)){
        spdlog::debug("Is not legal spend");
        return false;
    }
    for (char c : text){
        if (c == ' ') continue;
        auto character = char_to_enum(c);
        alphabet.decrement(character);
    }
    return true;
}

const Alphabet &CharacterStorageSystem::getAlphabet() {
    return alphabet;
}

void CharacterStorageSystem::pickupCharacter(Character c) {
    alphabet.increment(c);
}

bool CharacterStorageSystem::isLegalSpend(const std::string &word) {
    Alphabet dummyAlphabet = alphabet;
    for (char c : word){
        if (c == ' ') continue;
        auto character = char_to_enum(c);
        if (dummyAlphabet.getCount(character) <= 0){
            return false;
        }
        dummyAlphabet.decrement(character);
    }
    return true;
}

void CharacterStorageSystem::listenToEvents() {
    eventBus->listenToEvent<CharacterStorageEvent>(this, &CharacterStorageSystem::onSpend);
}


