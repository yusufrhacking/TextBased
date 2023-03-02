#include "InputProcessor.h"
#include <SDL2/SDL.h>
#include <spdlog/spdlog.h>

bool InputProcessor::processInput(SDL_Event event) {
    unsigned int eventType = event.type;
    bool result = true;
    switch(eventType){
        case SDL_QUIT:
            spdlog::info("SDL_QUIT Exercised");
            return false;
        case SDL_KEYDOWN:
            result = handleKeyPress(event);
            break;
    }
    return result;
}

bool InputProcessor::handleKeyPress(SDL_Event event){
    switch(event.key.keysym.sym){
        case SDLK_ESCAPE:
            spdlog::info("Escape key pressed; now exiting");
            return false;
    }
    return true;
}
