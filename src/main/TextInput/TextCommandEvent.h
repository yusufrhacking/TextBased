#ifndef TEXTBASED_TEXTCOMMANDEVENT_H
#define TEXTBASED_TEXTCOMMANDEVENT_H
#include "../EventSystem/Event.h"
#include <string>
#include <utility>

class TextCommandEvent : public Event {
public:
    explicit TextCommandEvent(std::string processedText){
        this->processedText = std::move(processedText);
    }

    std::string processedText;
};

#endif //TEXTBASED_TEXTCOMMANDEVENT_H
