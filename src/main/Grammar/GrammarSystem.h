#ifndef TEXTBASED_GRAMMARSYSTEM_H
#define TEXTBASED_GRAMMARSYSTEM_H
#include "GrammarEvent.h"
#include "../ECSObjects/System.h"

class GrammarSystem: public System {
public:
    GrammarSystem();
    void listenToEvents();
    void onGrammar(GrammarEvent& event);
    std::pair<std::string, std::string> splitCommandAndSubject(const std::string& text) const;


private:
    bool isCommandKeyword(const std::string &keyword) const;

    bool isSubjectKeyword(const std::string &keyword) const;
    std::set<std::string> commandKeywords;
    std::set<std::string> subjectKeywords;
};

#endif