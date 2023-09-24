#ifndef TEXTBASED_ENGINEERTERMINALEVENT_H
#define TEXTBASED_ENGINEERTERMINALEVENT_H

#include "../EventSystem/Event.h"
#include <string>
#include <utility>

struct EngineerTerminalEvent: public Event{
    std::string text;
    explicit EngineerTerminalEvent(std::string text): text(std::move(text)){}
};

#endif //TEXTBASED_ENGINEERTERMINALEVENT_H
