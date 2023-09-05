#ifndef TEXTBASED_WORDCOMPREHENSIONSYSTEM_H
#define TEXTBASED_WORDCOMPREHENSIONSYSTEM_H
#include "../HighLevel/ECSManager.h"
#include "ProcessedTextEvent.h"
#include "GameKeyEvent.h"
#include "TextInputEvent.h"
#include "../ECSObjects/System.h"

class WordComprehensionSystem: public System {
public:
    WordComprehensionSystem();
private:
    std::string text;
    bool listening_to_letters;
    void listenToEvents();
    void onGameKey(GameKeyEvent& event);
    void onText(TextInputEvent& event);
};


#endif //TEXTBASED_WORDCOMPREHENSIONSYSTEM_H
