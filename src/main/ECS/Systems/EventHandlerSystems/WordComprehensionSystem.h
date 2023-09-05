#ifndef TEXTBASED_WORDCOMPREHENSIONSYSTEM_H
#define TEXTBASED_WORDCOMPREHENSIONSYSTEM_H


#include "../../Design/Objects/System.h"
#include "../../../Helpers/EventSystem/Events/GameKeyEvent.h"
#include "../../../Helpers/EventSystem/Events/TextInputEvent.h"

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
