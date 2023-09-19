#include "CharacterStorageSystem.h"
#include "Alphabet.h"

CharacterStorageSystem::CharacterStorageSystem() = default;

bool CharacterStorageSystem::spendWord(std::string word) {
    Alphabet dummyAlphabet = alphabet;
    for (char c : word){

    }
    return false;
}

const Alphabet &CharacterStorageSystem::getAlphabet() {
    return alphabet;
}

void CharacterStorageSystem::pickupCharacter(Character c) {
    alphabet.increment(c);
}


