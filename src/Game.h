#ifndef TEXTBASED_GAME_H
#define TEXTBASED_GAME_H
#include <SDL2/SDL.h>
#include <SDL_ttf.h>
#include "spdlog/spdlog.h"
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

    void setup();

    void processInput();

    void update();

};


#endif //TEXTBASED_GAME_H
