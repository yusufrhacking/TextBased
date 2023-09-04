#ifndef TEXTBASED_KEYEVENT_H
#define TEXTBASED_KEYEVENT_H

#include "Event.h"
#include "SDL_keycode.h"
#include "SDL_scancode.h"

class KeyEvent: public Event{
public:
    char character;
    explicit KeyEvent(char character){
        this->character = character;

    }
    bool operator<(const KeyEvent& other) const {
        return this->character < other.character;
    }
};

#endif
