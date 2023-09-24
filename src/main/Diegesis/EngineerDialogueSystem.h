#ifndef TEXTBASED_ENGINEERDIALOGUESYSTEM_H
#define TEXTBASED_ENGINEERDIALOGUESYSTEM_H


#include "../Lettering/CharacterDepositEvent.h"

class EngineerDialogueSystem {
public:
    EngineerDialogueSystem();
private:
    bool isFirstLetter = false;
    void listenToEvents();
    void onLetter(CharacterDepositEvent& event); //on deposit, check if first one, then send this message
};


#endif //TEXTBASED_ENGINEERDIALOGUESYSTEM_H
