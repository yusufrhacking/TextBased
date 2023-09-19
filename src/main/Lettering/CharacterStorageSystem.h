#ifndef TEXTBASED_CHARACTERSTORAGESYSTEM_H
#define TEXTBASED_CHARACTERSTORAGESYSTEM_H
#include <string>
#include "Alphabet.h"
#include "../TextCommands/ProcessedTextEvent.h"
#include "../ECSObjects/System.h"

class CharacterStorageSystem: public System {
public:
    CharacterStorageSystem();
    void pickupCharacter(Character c);
    bool spendWord(const std::string& word);
    const Alphabet& getAlphabet();
private:
    Alphabet alphabet{10};

    bool isLegalSpend(const std::string &word);

    void listenToEvents();

    void onSpend(ProcessedTextEvent &event);
};


#endif //TEXTBASED_CHARACTERSTORAGESYSTEM_H
