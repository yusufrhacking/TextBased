#ifndef TEXTBASED_CHARACTERSTORAGESYSTEM_H
#define TEXTBASED_CHARACTERSTORAGESYSTEM_H
#include <string>
#include "Alphabet.h"
#include "../TextCommands/CharacterSpendEvent.h"
#include "../ECSObjects/System.h"
#include "CharacterDepositEvent.h"

class CharacterStorageSystem: public System {
public:
    CharacterStorageSystem();
    bool tryToSpendText(const std::string& text);
    bool isLegalSpend(const std::string &word);
    const Alphabet& getAlphabet();
private:
    Alphabet alphabet{};


    void listenToEvents();

    void onSpend(CharacterSpendEvent &event);

    void onDeposit(CharacterDepositEvent &event);
};


#endif //TEXTBASED_CHARACTERSTORAGESYSTEM_H
