#include "InputProcessor.h"
#include "../../../Helpers/EventSystem/EventBus/EventBus.h"
#include "SDL_keycode.h"
#include "../../../Helpers/EventSystem/Events/KeyEvent.h"
#include <SDL.h>
#include <spdlog/spdlog.h>

extern std::unique_ptr<EventBus> eventBus;

static int counter=0;

std::map<SDL_Scancode, GameKey> keyMappings = {
        { SDL_SCANCODE_W, GameKey::MOVE_UP },
        { SDL_SCANCODE_A, GameKey::MOVE_LEFT },
        { SDL_SCANCODE_S, GameKey::MOVE_DOWN },
        { SDL_SCANCODE_D, GameKey::MOVE_RIGHT }
};




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

    for(const auto& pair : keyMappings) {
        if(keyboard_state_array[pair.first]) {
            spdlog::trace("{} key noted", SDL_GetScancodeName(pair.first));
            eventBus->emitEvent<KeyEvent>(KeyEvent(pair.second));
        }
    }
    return true;

}
