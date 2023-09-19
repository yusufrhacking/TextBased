#ifndef TEXTBASED_CHARACTERSTORAGEEVENT_H
#define TEXTBASED_CHARACTERSTORAGEEVENT_H

#include "../EventSystem/Event.h"
#include <string>

struct CharacterStorageEvent: public Event{
    CharacterStorageEvent(std::string command, std::string subject): command(command), subject(subject) {}

    std::string command;
    std::string subject;
};

#endif //TEXTBASED_CHARACTERSTORAGEEVENT_H
