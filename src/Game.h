#ifndef TEXTBASED_GAME_H
#define TEXTBASED_GAME_H
#include <SDL2/SDL.h>
#include <SDL_ttf.h>
#include "spdlog/spdlog.h"
#include "Renderer/Renderer.h"
#include "InputProcessor/InputProcessor.h"
#include "ECS/Design/Managers/ECSManager.h"


class Game{

private:
        bool isRunning;
        Window* window;
        Renderer* renderer;
        InputProcessor* inputProcessor;
        ECSManager* manager;


public:

    void initialize();

    void run();

    void close();

    void setup();

    void processInput();

    void update();

};


#endif //TEXTBASED_GAME_H
