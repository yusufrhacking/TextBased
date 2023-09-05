#ifndef TEXTBASED_PROCESSEDTEXTEVENT_H
#define TEXTBASED_PROCESSEDTEXTEVENT_H
#include "../EventSystem/Event.h"
#include <string>
#include <utility>

class ProcessedTextEvent : public Event {
public:
    explicit ProcessedTextEvent(std::string processedText){
        this->processedText = std::move(processedText);
    }

    std::string processedText;
};

#endif //TEXTBASED_PROCESSEDTEXTEVENT_H
