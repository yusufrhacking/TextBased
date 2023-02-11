#include "InputProcessor.h"
#include <SDL2/SDL.h>

bool InputProcessor::processInput(SDL_Event event) {
    unsigned int eventType = event.type;
    bool result;
    switch(eventType){
        case SDL_QUIT:
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
            return false;
    }
    return true;
}
