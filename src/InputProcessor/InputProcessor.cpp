#include "InputProcessor.h"
#include <SDL2/SDL.h>

bool InputProcessor::processInput(SDL_Event event) {
    switch(event.type){
        case SDL_QUIT:
            return false;
        case SDL_KEYDOWN:
            if(event.key.keysym.sym == SDLK_ESCAPE){
                return false;
            }
            break;
    }
    return true;
}
