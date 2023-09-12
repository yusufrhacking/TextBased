#ifndef TEXTBASED_TEXTCOMMANDSYSTEM_H
#define TEXTBASED_TEXTCOMMANDSYSTEM_H
#include "../ECSObjects/System.h"
#include "../TextInput/TextCommandEvent.h"

class TextCommandSystem: public System {
public:
    TextCommandSystem();
private:
    void listenToEvents();
    void onCommand(TextCommandEvent& event);

    std::vector<std::string> getWords(std::string processedText);
};


#endif
