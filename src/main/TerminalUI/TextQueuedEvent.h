#ifndef TEXTBASED_TEXTQUEUEDEVENT_H
#define TEXTBASED_TEXTQUEUEDEVENT_H
#include <string>
#include <utility>
#include "../EventSystem/Event.h"


class TextQueuedEvent : public Event {
public:
    std::string text;

    explicit TextQueuedEvent(std::string text) {
        this->text = std::move(text);
    }
};

#endif