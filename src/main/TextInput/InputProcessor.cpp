#include "InputProcessor.h"
#include "SDL_keycode.h"
#include "../EventSystem/EventBus.h"
#include "TextInputEvent.h"
#include <SDL.h>
#include <spdlog/spdlog.h>

extern std::unique_ptr<EventBus> eventBus;

std::map<SDL_Scancode, GameKey> keyStateMappings = {
        { SDL_SCANCODE_UP, GameKey::MOVE_UP },
        { SDL_SCANCODE_LEFT, GameKey::MOVE_LEFT },
        { SDL_SCANCODE_DOWN, GameKey::MOVE_DOWN },
        { SDL_SCANCODE_RIGHT, GameKey::MOVE_RIGHT }
};

//std::map<SDL_Scancode, GameKey> keyStateMappings = {
//        { SDL_SCANCODE_W, GameKey::MOVE_UP },
//        { SDL_SCANCODE_A, GameKey::MOVE_LEFT },
//        { SDL_SCANCODE_S, GameKey::MOVE_DOWN },
//        { SDL_SCANCODE_D, GameKey::MOVE_RIGHT }
//};

std::map<SDL_KeyCode, GameKey> keyPressMappings = {
        {SDLK_RETURN, GameKey::TEXT_FLIP},
        {SDLK_BACKSPACE, GameKey::BACKSPACE},
        {SDLK_SPACE, GameKey::REPEAT_COMMAND}
};
void InputProcessor::updateKeyStates() {
    currentKeyStates = SDL_GetKeyboardState(nullptr);
}

void InputProcessor::processKeyPresses() {
    for (const auto& pair : keyStateMappings) {
        if (currentKeyStates[pair.first]) {
            eventBus->emitEvent<GameKeyEvent>(GameKeyEvent(pair.second));
            spdlog::info("{} key pressed", SDL_GetScancodeName(pair.first));
        }
    }
}


bool InputProcessor::processInput() {
    SDL_Event sdlEvent;
    while (SDL_PollEvent(&sdlEvent)) {
        if (sdlEvent.type == SDL_QUIT) {
            spdlog::critical("SDL QUIT Executed");
            return false;
        }
        if (sdlEvent.type == SDL_TEXTINPUT) {
            eventBus->emitEvent<TextInputEvent>(TextInputEvent(sdlEvent.text));
        }
    }

    updateKeyStates(); // Update the state of all keys
    processKeyPresses(); // Process the key presses

    // Check for the ESC key
    if (currentKeyStates[SDL_SCANCODE_ESCAPE]) {
        spdlog::critical("Escape key pressed");
        return false;
    }

    return true;
}
