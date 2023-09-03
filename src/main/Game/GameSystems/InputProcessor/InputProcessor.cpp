#include "InputProcessor.h"
#include "../../../Helpers/EventSystem/EventBus/EventBus.h"
#include "SDL_keycode.h"
#include "../../../Helpers/EventSystem/Events/KeyEvent.h"
#include <SDL.h>
#include <spdlog/spdlog.h>

extern std::unique_ptr<EventBus> eventBus;

static int counter=0;



bool InputProcessor::processInput(SDL_Event event) {
    unsigned int eventType = event.type;
    if(eventType == SDL_QUIT){
        spdlog::critical("SDL QUIT Executed");
        return false;
    }
    return readInput(static_cast<SDL_KeyCode>(event.key.keysym.sym));
}

bool InputProcessor::readInput(SDL_KeyCode key){
    SDL_PumpEvents();
    const Uint8 *keyboard_state_array = SDL_GetKeyboardState(nullptr);

    if(key == SDLK_ESCAPE){
        spdlog::trace("Escape key pressed");
        return false;
    }
    if (keyboard_state_array[SDL_SCANCODE_W]){
        spdlog::trace("W key noted");
        eventBus->emitEvent<KeyEvent>(KeyEvent(W_KEY));
    }
    if (keyboard_state_array[SDL_SCANCODE_A]){
        spdlog::trace("A key noted");
        eventBus->emitEvent<KeyEvent>(KeyEvent(A_KEY));
    }
    if (keyboard_state_array[SDL_SCANCODE_S]){
        spdlog::trace("S key noted");
        eventBus->emitEvent<KeyEvent>(KeyEvent(S_KEY));
    }
    if (keyboard_state_array[SDL_SCANCODE_D]){
        spdlog::trace("D key noted");
        eventBus->emitEvent<KeyEvent>(KeyEvent(D_KEY));
    }
    if (keyboard_state_array[SDL_SCANCODE_SPACE]){
        spdlog::trace("SPACE key noted");
        eventBus->emitEvent<KeyEvent>(KeyEvent(SPACE_KEY));
    }

    return true;
}
