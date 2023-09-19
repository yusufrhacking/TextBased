#ifndef TEXTBASED_GRAMMAREVENT_H
#define TEXTBASED_GRAMMAREVENT_H

#include "../EventSystem/Event.h"
#include <string>

struct GrammarEvent: public Event{
    explicit GrammarEvent(std::string text){
        this->text = std::move(text);
    }

    std::string text;
};

#endif //TEXTBASED_GRAMMAREVENT_H
