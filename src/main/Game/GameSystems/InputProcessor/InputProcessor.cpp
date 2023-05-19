#include "InputProcessor.h"
#include "../../../Helpers/EventSystem/EventBus/EventBus.h"
#include "SDL_keycode.h"
#include "../../../Helpers/EventSystem/Events/KeyEvent.h"
#include <SDL.h>
extern std::unique_ptr<EventBus> eventBus;

const Uint8 *keyboard_state_array = SDL_GetKeyboardState(nullptr);


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
    if(key == SDLK_ESCAPE){
        return false;
    }
    if (keyboard_state_array[SDL_SCANCODE_W] && !(keyboard_state_array[SDL_SCANCODE_S]))
    {
        KEY_TYPE keyType = W_KEY;
        eventBus->emitEvent<KeyEvent>(keyType);

    }
    else if (!keyboard_state_array[SDL_SCANCODE_W] && keyboard_state_array[SDL_SCANCODE_S])
    {
        KEY_TYPE keyType = S_KEY;
        eventBus->emitEvent<KeyEvent>(keyType);
    }

    if (keyboard_state_array[SDL_SCANCODE_D] && !keyboard_state_array[SDL_SCANCODE_A])
    {
        KEY_TYPE keyType = D_KEY;
        eventBus->emitEvent<KeyEvent>(keyType);
    }
    else if (!keyboard_state_array[SDL_SCANCODE_D] && keyboard_state_array[SDL_SCANCODE_A])
    {
        KEY_TYPE keyType = A_KEY;
        eventBus->emitEvent<KeyEvent>(keyType);
    }
    return true;
}
