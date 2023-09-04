#ifndef TEXTBASED_WORDCOMPREHENSIONSYSTEM_H
#define TEXTBASED_WORDCOMPREHENSIONSYSTEM_H


#include "../../Design/Objects/System.h"
#include "../../../Helpers/EventSystem/Events/GameKeyEvent.h"

class WordComprehensionSystem: public System {
public:
    WordComprehensionSystem();
    std::string pop_text();
private:
    std::string text;
    bool listening_to_letters;
    void listenToEvents();
    void onText(GameKeyEvent& event);
};


#endif //TEXTBASED_WORDCOMPREHENSIONSYSTEM_H
