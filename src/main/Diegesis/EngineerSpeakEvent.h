

#ifndef TEXTBASED_ENGINEERSPEAKEVENT_H
#define TEXTBASED_ENGINEERSPEAKEVENT_H

#include <string>
#include "../EventSystem/Event.h"

struct EngineerSpeakEvent: public Event{
    std::string text;
    explicit EngineerSpeakEvent(std::string text): text(std::move(text)){}
};

#endif //TEXTBASED_ENGINEERSPEAKEVENT_H
