#include "CharacterStorageSystem.h"
#include "Alphabet.h"

CharacterStorageSystem::CharacterStorageSystem() = default;

bool CharacterStorageSystem::spendWord(std::string word) {
    Alphabet dummyAlphabet = alphabet;
    for (char c : word){
        auto character = char_to_enum(c);
        if (dummyAlphabet.getCount(character) <= 0){
            return false;
        }
        dummyAlphabet.decrement(character);
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


