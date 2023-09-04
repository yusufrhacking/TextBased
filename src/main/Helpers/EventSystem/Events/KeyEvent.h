#ifndef TEXTBASED_KEYEVENT_H
#define TEXTBASED_KEYEVENT_H

#include "Event.h"
#include "SDL_keycode.h"
#include "SDL_scancode.h"

enum KEY_TYPE{
    W_KEY,
    A_KEY,
    S_KEY,
    D_KEY,
    SPACE_KEY,
    NONE_KEY
};


class KeyEvent: public Event{
public:
    KEY_TYPE keyType;
    explicit KeyEvent(KEY_TYPE keyType){
        this->keyType = keyType;
    }
    explicit KeyEvent(SDL_KeyCode keyType){
        this->keyType = mapFromSDL(keyType);
    }
    bool operator<(const KeyEvent& other) const {
        return this->keyType < other.keyType;
    }



private:
    KEY_TYPE mapFromSDL(SDL_KeyCode keyType){
        if (keyType == SDLK_a){
            return A_KEY;
        }
        if (keyType == SDLK_w){
            return W_KEY;
        }
        if (keyType == SDLK_s){
            return S_KEY;
        }
        if (keyType == SDLK_d){
            return D_KEY;
        }
        return NONE_KEY;
    }
};

#endif
