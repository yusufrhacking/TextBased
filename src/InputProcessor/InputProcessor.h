#ifndef TEXTBASED_INPUTPROCESSOR_H
#define TEXTBASED_INPUTPROCESSOR_H
#include "SDL2/SDL.h"

class InputProcessor {
public:
    bool ProcessInput(SDL_Event event);
};


#endif //TEXTBASED_INPUTPROCESSOR_H
