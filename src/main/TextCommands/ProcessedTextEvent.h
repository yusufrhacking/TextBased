#ifndef TEXTBASED_PROCESSEDTEXTEVENT_H
#define TEXTBASED_PROCESSEDTEXTEVENT_H

#include "../EventSystem/Event.h"
#include <string>

struct ProcessedTextEvent: public Event{
    explicit ProcessedTextEvent(std::string processedText){
        this->processedText = std::move(processedText);
    }

    std::string processedText;
};

#endif //TEXTBASED_PROCESSEDTEXTEVENT_H
