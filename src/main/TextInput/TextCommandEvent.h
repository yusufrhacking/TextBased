#ifndef TEXTBASED_TEXTCOMMANDEVENT_H
#define TEXTBASED_TEXTCOMMANDEVENT_H
#include "../EventSystem/Event.h"
#include "../TextCommands/Command.h"
#include <string>
#include <utility>

class TextCommandEvent : public Event {
public:
    Command command;
    TextCommandEvent(std::string command, std::string subject): command(std::move(command), std::move(subject)){}

//    std::string command, subject;
};

#endif //TEXTBASED_TEXTCOMMANDEVENT_H
