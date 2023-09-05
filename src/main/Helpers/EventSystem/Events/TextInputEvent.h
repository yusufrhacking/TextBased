#ifndef TEXTBASED_TEXTINPUTEVENT_H
#define TEXTBASED_TEXTINPUTEVENT_H
#include "Event.h"
#include <SDL.h>

class TextInputEvent : public Event {
public:
    explicit TextInputEvent(SDL_TextInputEvent textEvent){
        this->textEvent = textEvent;
    }

    SDL_TextInputEvent textEvent;
};

#endif //TEXTBASED_TEXTINPUTEVENT_H
