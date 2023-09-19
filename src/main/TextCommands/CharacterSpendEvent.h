#ifndef TEXTBASED_CHARACTERSPENDEVENT_H
#define TEXTBASED_CHARACTERSPENDEVENT_H

#include "../EventSystem/Event.h"
#include <string>

struct CharacterSpendEvent: public Event{
    CharacterSpendEvent(std::string command, std::string subject): command(command), subject(subject) {}

    std::string command;
    std::string subject;
};

#endif //TEXTBASED_CHARACTERSPENDEVENT_H
