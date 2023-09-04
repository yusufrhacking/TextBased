#ifndef TEXTBASED_KEYEVENT_H
#define TEXTBASED_KEYEVENT_H
#include "Event.h"
#include <SDL.h>

enum class GameKey {
    MOVE_UP,
    MOVE_LEFT,
    MOVE_DOWN,
    MOVE_RIGHT,
    UNKNOWN // Used for unmapped keys
};

class KeyEvent : public Event {
public:
    explicit KeyEvent(SDL_Keycode keycode);

    GameKey getKey() const { return keyType; }

private:
    GameKey keyType;
    static GameKey ConvertFromSDL(SDL_Keycode keycode);
};

#endif
