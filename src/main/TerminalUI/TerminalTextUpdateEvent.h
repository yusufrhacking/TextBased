#ifndef TEXTBASED_TERMINALTEXTUPDATEEVENT_H
#define TEXTBASED_TERMINALTEXTUPDATEEVENT_H

#include <string>
#include "../EventSystem/Event.h"

struct TerminalTextUpdateEvent: public Event{
    std::string text;
    explicit TerminalTextUpdateEvent(std::string text): text(text) {}
};

#endif //TEXTBASED_TERMINALTEXTUPDATEEVENT_H
