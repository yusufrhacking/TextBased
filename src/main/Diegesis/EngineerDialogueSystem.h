#ifndef TEXTBASED_ENGINEERDIALOGUESYSTEM_H
#define TEXTBASED_ENGINEERDIALOGUESYSTEM_H


#include "../Lettering/CharacterDepositEvent.h"
#include "../ECSObjects/System.h"

class EngineerDialogueSystem: public System {
public:
    EngineerDialogueSystem();
private:
    bool isFirstLetter = true;
    void listenToEvents();
    void onLetter(CharacterDepositEvent& event); //on deposit, check if first one, then send this message
};


#endif //TEXTBASED_ENGINEERDIALOGUESYSTEM_H
