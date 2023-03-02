#ifndef TEXTBASED_INPUTPROCESSOR_H
#define TEXTBASED_INPUTPROCESSOR_H
#include "SDL2/SDL.h"

class InputProcessor {
public:
    InputProcessor() = default;
    ~InputProcessor() = default;
    bool processInput(SDL_Event event);

private:
    bool handleKeyPress(SDL_Event event);
};


#endif
