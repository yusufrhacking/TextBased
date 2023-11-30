#include <spdlog/spdlog.h>
#include "CharacterStorageSystem.h"
#include "Alphabet.h"
#include "../EventSystem/EventBus.h"
#include "../TextCommands/CharacterSpendEvent.h"
#include "../TextInput/TextCommandEvent.h"
#include "CharacterDepositEvent.h"
#include "Letter.h"
#include "LetterBankRenderSystem.h"
#include "../HighLevel/ECSManager.h"
#include "WordDepositEvent.h"

extern std::unique_ptr<ECSManager> ecsManager;
extern std::unique_ptr<EventBus> eventBus;

CharacterStorageSystem::CharacterStorageSystem() {
    listenToEvents();
}

void CharacterStorageSystem::onSpend(CharacterSpendEvent &event) {
    bool result = tryToSpendText(event.subject);
    if (result) {
        eventBus->emitEvent<TextCommandEvent>(event.command, event.subject);
    }
}

bool CharacterStorageSystem::tryToSpendText(const std::string &text) {
    if (!isLegalSpend(text)) {
        spdlog::debug("Is not legal spend");
        return false;
    }
    for (char c: text) {
        if (c == ' ') continue;
        auto character = char_to_enum(c);
        alphabet.decrement(character);
    }
    return true;
}

const Alphabet &CharacterStorageSystem::getAlphabet() {
    return alphabet;
}

bool CharacterStorageSystem::isLegalSpend(const std::string &word) {
    Alphabet dummyAlphabet = alphabet;
    for (char c: word) {
        if (c == ' ') continue;
        auto character = char_to_enum(c);
        if (dummyAlphabet.getCount(character) <= 0) {
            return false;
        }
        dummyAlphabet.decrement(character);
    }
    return true;
}


void CharacterStorageSystem::onDeposit(CharacterDepositEvent &event) {
    if (!ecsManager->hasSystem<LetterBankRenderSystem>()){
        ecsManager->addSystem<LetterBankRenderSystem>();
    }
    spdlog::debug("Found letter: {}", enum_to_char(event.letter));
    alphabet.increment(event.letter);
}

void CharacterStorageSystem::listenToEvents() {
    eventBus->listenToEvent<CharacterSpendEvent>(this, &CharacterStorageSystem::onSpend);
    eventBus->listenToEvent<CharacterDepositEvent>(this, &CharacterStorageSystem::onDeposit);
    eventBus->listenToEvent<WordDepositEvent>(this, &CharacterStorageSystem::onWordDeposit);
}

void CharacterStorageSystem::onWordDeposit(WordDepositEvent &event) {
    spdlog::trace("Word deposited");
    for (auto letter: event.letters){
        alphabet.increment(letter);
    }
}


