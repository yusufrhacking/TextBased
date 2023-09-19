#ifndef TEXTBASED_GRAMMARSYSTEM_H
#define TEXTBASED_GRAMMARSYSTEM_H
#include "GrammarEvent.h"
#include "../ECSObjects/System.h"

class GrammarSystem: public System {
public:
    GrammarSystem();
    void listenToEvents();
    void onGrammar(GrammarEvent& event);
};


#endif //TEXTBASED_GRAMMARSYSTEM_H
