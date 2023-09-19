#ifndef TEXTBASED_TEXTCOMMANDSYSTEM_H
#define TEXTBASED_TEXTCOMMANDSYSTEM_H
#include "../ECSObjects/System.h"
#include "../TextInput/ProspectiveTextCommandEvent.h"
#include "../Grammar/GrammarSystem.h"
#include "../Lettering/CharacterStorageSystem.h"

class TextCommandSystem: public System {
public:
    TextCommandSystem();
private:
    void listenToEvents();
    void onCommand(ProspectiveTextCommandEvent& event);

};


#endif
