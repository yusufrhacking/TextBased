#ifndef TEXTBASED_GAME_H
#define TEXTBASED_GAME_H
#include <SDL2/SDL.h>
#include <SDL_ttf.h>
#include "spdlog/spdlog.h"
#include "Renderer/Renderer.h"
#include "InputProcessor/InputProcessor.h"
#include "ECS/Design/Managers/ECSManager.h"
#include <memory>

class Game{

private:
        bool isRunning;
        std::unique_ptr<Window> window;
        std::unique_ptr<Renderer> renderer;
        std::unique_ptr<InputProcessor> inputProcessor;
        std::unique_ptr<ECSManager> manager;


public:

    Game();
    ~Game();

    void initialize();

    void run();

    void close();

    void setup();

    void processInput();

    void update();

};


#endif //TEXTBASED_GAME_H
