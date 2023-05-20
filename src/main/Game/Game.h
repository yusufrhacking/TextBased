#ifndef TEXTBASED_GAME_H
#define TEXTBASED_GAME_H
#include <SDL.h>
#include <SDL_ttf.h>
#include "../ECS/Design/Managers/ECSManager.h"
#include "../ECS/Components/PositionComponent.h"
#include "../ECS/Components/MovementComponent.h"
#include "../ECS/Systems/UpdateSystems/AutonomousMovementSystem.h"
#include "GameSystems/Window/Window.h"
#include "GameSystems/InputProcessor/InputProcessor.h"
#include "GameSystems/Renderer/Renderer.h"
#include "GameManager.h"
#include <memory>

const size_t FPS = 60;
const size_t MILLISECS_PER_FRAME = 1000 / FPS;

class Game{



private:
        bool isRunning;
        std::shared_ptr<Renderer> renderer;
        std::unique_ptr<InputProcessor> inputProcessor;
        std::unique_ptr<GameManager> kirk;
        size_t millisecsPreviousFrame = 0;

        double waitForDeltaTime();

        void setup();

        void processInput();

        void update();

        void render();


public:

    Game();
    ~Game();

    void initialize();

    void run();

    void close();
};


#endif //TEXTBASED_GAME_H
