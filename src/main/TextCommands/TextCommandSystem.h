#ifndef TEXTBASED_TEXTCOMMANDSYSTEM_H
#define TEXTBASED_TEXTCOMMANDSYSTEM_H
#include "../ECSObjects/System.h"
#include "../TextInput/TextCommandEvent.h"
#include "../Grammar/GrammarSystem.h"
#include "../Lettering/CharacterStorageSystem.h"

class TextCommandSystem: public System {
public:
    TextCommandSystem();
private:
    GrammarSystem grammarSystem;
    CharacterStorageSystem characterStorage;
    void listenToEvents();
    void onCommand(TextCommandEvent& event);

};


#endif
