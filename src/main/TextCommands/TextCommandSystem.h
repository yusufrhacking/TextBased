#ifndef TEXTBASED_TEXTCOMMANDSYSTEM_H
#define TEXTBASED_TEXTCOMMANDSYSTEM_H
#include "../ECSObjects/System.h"
#include "../TextInput/TextCommandEvent.h"
#include "../Grammar/GrammarSystem.h"

class TextCommandSystem: public System {
public:
    TextCommandSystem();
private:
    GrammarSystem grammarSystem;
    void listenToEvents();
    void onCommand(TextCommandEvent& event);

};


#endif
