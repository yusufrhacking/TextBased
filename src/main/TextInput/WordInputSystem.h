#ifndef TEXTBASED_WORDINPUTSYSTEM_H
#define TEXTBASED_WORDINPUTSYSTEM_H
#include "../HighLevel/ECSManager.h"
#include "ProspectiveTextCommandEvent.h"
#include "GameKeyEvent.h"
#include "TextInputEvent.h"
#include "../ECSObjects/System.h"

class WordInputSystem: public System {
public:
    WordInputSystem();
private:
    std::string text;
    std::string lastCommand;
    bool listening_to_letters;
    void listenToEvents();
    void onGameKey(GameKeyEvent& event);
    void onText(TextInputEvent& event);

    void handleTextFlip();

    void handleBackSpace();

    void handleRepeatCommand();
};


#endif //TEXTBASED_WORDINPUTSYSTEM_H
