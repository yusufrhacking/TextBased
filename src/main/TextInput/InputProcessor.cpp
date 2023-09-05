#include "InputProcessor.h"
#include "../../../Helpers/EventSystem/EventBus/EventBus.h"
#include "SDL_keycode.h"
#include "../../../Helpers/EventSystem/Events/GameKeyEvent.h"
#include "../../../Helpers/EventSystem/Events/TextInputEvent.h"
#include <SDL.h>
#include <spdlog/spdlog.h>

extern std::unique_ptr<EventBus> eventBus;

std::map<SDL_Scancode, GameKey> keyStateMappings = {
        { SDL_SCANCODE_UP, GameKey::MOVE_UP },
        { SDL_SCANCODE_LEFT, GameKey::MOVE_LEFT },
        { SDL_SCANCODE_DOWN, GameKey::MOVE_DOWN },
        { SDL_SCANCODE_RIGHT, GameKey::MOVE_RIGHT }
};

std::map<SDL_KeyCode, GameKey> keyPressMappings = {
        {SDLK_SPACE, GameKey::TEXT_FLIP},
        {SDLK_RETURN, GameKey::END_OF_TEXT}
};

bool InputProcessor::processInput(SDL_Event event) {
    unsigned int eventType = event.type;
    if(eventType == SDL_QUIT){
        spdlog::critical("SDL QUIT Executed");
        return false;
    }
    return readInput(event);
}

bool InputProcessor::readInput(SDL_Event event){
    auto key = static_cast<SDL_KeyCode>(event.key.keysym.sym);
    if (event.type == SDL_KEYDOWN){
        auto it = keyPressMappings.find(key);
        if (it != keyPressMappings.end()) {
            eventBus->emitEvent<GameKeyEvent>(GameKeyEvent(it->second));
        }
    } else if(event.type == SDL_TEXTINPUT){
        eventBus->emitEvent<TextInputEvent>(TextInputEvent(event.text));
    }
    SDL_PumpEvents();
    const Uint8 *keyboard_state_array = SDL_GetKeyboardState(nullptr);

    if(key == SDLK_ESCAPE){
        spdlog::trace("Escape key pressed");
        return false;
    }

    for(const auto& scanCodeGameKeyPair : keyStateMappings) {
        if(keyboard_state_array[scanCodeGameKeyPair.first]) {
            spdlog::trace("{} key noted", SDL_GetScancodeName(scanCodeGameKeyPair.first));
            eventBus->emitEvent<GameKeyEvent>(GameKeyEvent(scanCodeGameKeyPair.second));
        }
    }



    return true;
}
