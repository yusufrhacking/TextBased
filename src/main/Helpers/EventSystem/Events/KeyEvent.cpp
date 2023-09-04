#include "KeyEvent.h"

KeyEvent::KeyEvent(SDL_Keycode keycode) : keyType(ConvertFromSDL(keycode)) {

}

GameKey KeyEvent::ConvertFromSDL(SDL_Keycode keycode) {
    switch (keycode) {
        case SDLK_w: return GameKey::MOVE_UP;
        case SDLK_a: return GameKey::MOVE_LEFT;
        case SDLK_s: return GameKey::MOVE_DOWN;
        case SDLK_d: return GameKey::MOVE_RIGHT;
        default: return GameKey::UNKNOWN;
    }
}
