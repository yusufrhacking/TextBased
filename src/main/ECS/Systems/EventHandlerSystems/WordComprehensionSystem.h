#ifndef TEXTBASED_WORDCOMPREHENSIONSYSTEM_H
#define TEXTBASED_WORDCOMPREHENSIONSYSTEM_H


#include "../../Design/Objects/System.h"
#include "../../../Helpers/EventSystem/Events/KeyEvent.h"

class WordComprehensionSystem: public System {
public:
    WordComprehensionSystem();
    std::string pop_text();
private:
    std::string text;
    bool listening_to_letters;
    void listenToEvents();
    void onText(KeyEvent& event);
};


#endif //TEXTBASED_WORDCOMPREHENSIONSYSTEM_H
