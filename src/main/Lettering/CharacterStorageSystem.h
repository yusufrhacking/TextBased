#ifndef TEXTBASED_CHARACTERSTORAGESYSTEM_H
#define TEXTBASED_CHARACTERSTORAGESYSTEM_H
#include <string>
#include "Alphabet.h"

class CharacterStorageSystem {
public:
    CharacterStorageSystem();
    void pickupCharacter(Character c);
    bool spendWord(const std::string& word);
    const Alphabet& getAlphabet();
private:
    Alphabet alphabet{};

    bool isLegalSpend(const std::string &word);
};


#endif //TEXTBASED_CHARACTERSTORAGESYSTEM_H
