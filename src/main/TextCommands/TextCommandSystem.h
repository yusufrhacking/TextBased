#ifndef TEXTBASED_TEXTCOMMANDSYSTEM_H
#define TEXTBASED_TEXTCOMMANDSYSTEM_H
#include "../ECSObjects/System.h"
#include "../TextInput/ProcessedTextEvent.h"

class TextCommandSystem: public System {
public:
    TextCommandSystem();
private:
    void listenToEvents();
    void onCommand(ProcessedTextEvent& event);
};


#endif
