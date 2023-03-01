#ifndef TEXTBASED_GAME_H
#define TEXTBASED_GAME_H
#include <SDL2/SDL.h>
#include <SDL_ttf.h>
#include "spdlog/spdlog.h"
#include "Renderer/Renderer.h"
#include "InputProcessor/InputProcessor.h"
#include "ECS/Design/Managers/ECSManager.h"
#include "ECS/Components/PositionComponent.h"
#include "ECS/Components/MovementComponent.h"
#include "ECS/Systems/MovementSystem.h"
#include <memory>

const size_t FPS = 60;
const size_t MILLISECS_PER_FRAME = 1000 / FPS;
extern std::unique_ptr<ECSManager> manager;

class Game{



private:
        bool isRunning;
        std::unique_ptr<Window> window;
        std::unique_ptr<Renderer> renderer;
        std::unique_ptr<InputProcessor> inputProcessor;
        size_t millisecsPreviousFrame = 0;


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
