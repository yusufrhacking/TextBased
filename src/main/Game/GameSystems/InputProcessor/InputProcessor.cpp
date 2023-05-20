#include "InputProcessor.h"
#include "../../../Helpers/EventSystem/EventBus/EventBus.h"
#include "SDL_keycode.h"
#include "../../../Helpers/EventSystem/Events/KeyEvent.h"
#include <SDL.h>
extern std::unique_ptr<EventBus> eventBus;

static int counter=0;

const Uint8 *keyboard_state_array = SDL_GetKeyboardState(nullptr);


bool InputProcessor::processInput(SDL_Event event) {
    unsigned int eventType = event.type;
    bool result = true;
    switch(eventType){
        case SDL_QUIT:
            return false;
        case SDL_KEYDOWN:
            break;
        default:
            break;
    }
    result = readInput(static_cast<SDL_KeyCode>(event.key.keysym.sym));

    return result;
}

bool InputProcessor::readInput(SDL_KeyCode key){
    if(key == SDLK_ESCAPE){
        return false;
    }
    if (keyboard_state_array[SDL_SCANCODE_W]){
        eventBus->emitEvent<KeyEvent>(KeyEvent(W_KEY));
    }
    if (keyboard_state_array[SDL_SCANCODE_A]){
        eventBus->emitEvent<KeyEvent>(KeyEvent(A_KEY));
    }
    if (keyboard_state_array[SDL_SCANCODE_S]){
        eventBus->emitEvent<KeyEvent>(KeyEvent(S_KEY));
    }
    if (keyboard_state_array[SDL_SCANCODE_D]){
        printf("Going right: %d\n", counter);
        counter++;
        eventBus->emitEvent<KeyEvent>(KeyEvent(D_KEY));
    }
    return true;
}
