#ifndef TEXTBASED_INPUTPROCESSOR_H
#define TEXTBASED_INPUTPROCESSOR_H
#include <SDL.h>
#include <set>
#include <string>
#include "GameKeyEvent.h"

class InputProcessor {
public:
    InputProcessor() = default;
    ~InputProcessor() = default;
    bool processInput();

private:
    std::string text;
    const Uint8* currentKeyStates;
    void updateKeyStates();
    void processKeyPresses();
};


#endif
