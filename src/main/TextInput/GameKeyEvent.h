#ifndef TEXTBASED_GAMEKEYEVENT_H
#define TEXTBASED_GAMEKEYEVENT_H
#include "../EventSystem/Event.h"
#include <SDL.h>

enum class GameKey {
    MOVE_UP,
    MOVE_LEFT,
    MOVE_DOWN,
    MOVE_RIGHT,
    TEXT_FLIP,
    END_OF_TEXT,
    BACKSPACE,
    REPEAT_COMMAND
};

class GameKeyEvent : public Event {
public:
    explicit GameKeyEvent(GameKey key);

    [[nodiscard]] GameKey getKey() const { return gameKey; }

private:
    GameKey gameKey;
};

#endif
