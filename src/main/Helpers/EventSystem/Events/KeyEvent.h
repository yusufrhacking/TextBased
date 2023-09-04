#ifndef TEXTBASED_KEYEVENT_H
#define TEXTBASED_KEYEVENT_H
#include "Event.h"
#include <SDL.h>

enum class GameKey {
    MOVE_UP,
    MOVE_LEFT,
    MOVE_DOWN,
    MOVE_RIGHT,
    UNKNOWN //Unmapped
};
class KeyEvent : public Event {
public:
    explicit KeyEvent(GameKey key);

    [[nodiscard]] GameKey getKey() const { return gameKey; }

private:
    GameKey gameKey;
};

#endif
