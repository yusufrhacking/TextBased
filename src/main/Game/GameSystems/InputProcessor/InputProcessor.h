#ifndef TEXTBASED_INPUTPROCESSOR_H
#define TEXTBASED_INPUTPROCESSOR_H
#include <SDL.h>
#include <set>
#include "../../../Helpers/EventSystem/Events/GameKeyEvent.h"

class InputProcessor {
    public:
        InputProcessor() = default;
        ~InputProcessor() = default;
        bool processInput(SDL_Event event);

    private:
        bool readInput(SDL_Event event);
};


#endif
