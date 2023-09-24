#ifndef TEXTBASED_TEXTCOMMANDEVENT_H
#define TEXTBASED_TEXTCOMMANDEVENT_H
#include "../EventSystem/Event.h"
#include <string>
#include <utility>

class TextCommandEvent : public Event {
public:
    TextCommandEvent(std::string command, std::string subject): command(command), subject(subject) {}

    std::string command, subject;
};

#endif //TEXTBASED_TEXTCOMMANDEVENT_H
