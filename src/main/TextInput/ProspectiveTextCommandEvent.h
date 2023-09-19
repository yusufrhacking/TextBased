#ifndef TEXTBASED_PROSPECTIVETEXTCOMMANDEVENT_H
#define TEXTBASED_PROSPECTIVETEXTCOMMANDEVENT_H
#include "../EventSystem/Event.h"
#include <string>
#include <utility>

class ProspectiveTextCommandEvent : public Event {
public:
    ProspectiveTextCommandEvent(std::string command, std::string subject): command(command), subject(subject) {}

    std::string command, subject;
};

#endif //TEXTBASED_PROSPECTIVETEXTCOMMANDEVENT_H
