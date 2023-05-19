#include "InputProcessor.h"
#include "../../../Helpers/EventSystem/EventBus/EventBus.h"
#include "SDL_keycode.h"
#include "../../../Helpers/EventSystem/Events/KeyEvent.h"
#include <SDL.h>
extern std::unique_ptr<EventBus> eventBus;

bool InputProcessor::processInput(SDL_Event event) {
    unsigned int eventType = event.type;
    bool result = true;
    switch(eventType){
        case SDL_QUIT:
            return false;
        case SDL_KEYDOWN:
            result = handleKeyPress(static_cast<SDL_KeyCode>(event.key.keysym.sym));
            break;

        default:
            break;
    }
    return result;
}

bool InputProcessor::handleKeyPress(SDL_KeyCode key){
    KEY_TYPE keyType;
    switch(key){
        case SDLK_ESCAPE:
            return false;
        case SDLK_w:
            keyType = W_KEY; break;
        case SDLK_a:
            keyType = A_KEY; break;
        case SDLK_s:
            keyType = S_KEY; break;
        case SDLK_d:
            keyType = D_KEY; break;
        default:
            break;
    }
    eventBus->emitEvent<KeyEvent>(keyType);
    return true;
}
