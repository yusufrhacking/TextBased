#ifndef TEXTBASED_GAME_H
#define TEXTBASED_GAME_H
#include <SDL2/SDL.h>
#include <SDL_ttf.h>
#include "Renderer/Renderer.h"
#include "InputProcessor/InputProcessor.h"


class Game{

private:
        bool isRunning;
        Window* window;
        Renderer* renderer;
        InputProcessor* inputProcessor;



public:

    void initialize();

    void run();

    void close();

    void Setup();

    void ProcessInput();

    void Update();

};


#endif //TEXTBASED_GAME_H
