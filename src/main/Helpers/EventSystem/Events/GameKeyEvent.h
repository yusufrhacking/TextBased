#ifndef TEXTBASED_GAMEKEYEVENT_H
#define TEXTBASED_GAMEKEYEVENT_H
#include "Event.h"
#include <SDL.h>

enum class GameKey {
    MOVE_UP,
    MOVE_LEFT,
    MOVE_DOWN,
    MOVE_RIGHT,
    UNKNOWN //Unmapped
};
class GameKeyEvent : public Event {
public:
    explicit GameKeyEvent(GameKey key);

    [[nodiscard]] GameKey getKey() const { return gameKey; }

private:
    GameKey gameKey;
};

#endif
