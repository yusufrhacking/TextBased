#include "CharacterStorageSystem.h"
#include "Alphabet.h"
#include "../EventSystem/EventBus.h"
#include "../TextCommands/ProcessedTextEvent.h"
#include "../TextInput/TextCommandEvent.h"

extern std::unique_ptr<EventBus> eventBus;


CharacterStorageSystem::CharacterStorageSystem() {
    listenToEvents();
}

void CharacterStorageSystem::onSpend(ProcessedTextEvent& event){
    eventBus->emitEvent<TextCommandEvent>(event.processedText);
}

bool CharacterStorageSystem::spendWord(const std::string& word) {
    if (!isLegalSpend(word)){
        return false;
    }
    for (char c : word){
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
        auto character = char_to_enum(c);
        if (dummyAlphabet.getCount(character) <= 0){
            return false;
        }
        dummyAlphabet.decrement(character);
    }
    return true;
}

void CharacterStorageSystem::listenToEvents() {
    eventBus->listenToEvent<ProcessedTextEvent>(this, &CharacterStorageSystem::onSpend);
}


