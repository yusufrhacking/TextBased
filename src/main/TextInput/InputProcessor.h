#ifndef TEXTBASED_INPUTPROCESSOR_H
#define TEXTBASED_INPUTPROCESSOR_H
#include <SDL.h>
#include <set>
#include <string>

class InputProcessor {
    public:
        InputProcessor() = default;
        ~InputProcessor() = default;
        bool processInput(SDL_Event event);

    private:
        std::string text;
        bool readInput(SDL_Event event);
};


#endif
