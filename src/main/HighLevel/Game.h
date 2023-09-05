#ifndef TEXTBASED_GAME_H
#define TEXTBASED_GAME_H
#include <SDL.h>
#include <SDL_ttf.h>
#include "ECSManager.h"
#include "../TextInput/InputProcessor.h"
#include "../Rendering/Renderer.h"
#include "../Rendering/SDLRenderer.h"
#include "GameManager.h"
#include <memory>
#include <stdexcept>
#include "spdlog/spdlog.h"

const size_t FPS = 60;
const size_t MILLISECS_PER_FRAME = 1000 / FPS;


class Game{

private:
        bool isRunning;
        std::shared_ptr<Renderer> renderer;
        std::unique_ptr<InputProcessor> inputProcessor;
        std::unique_ptr<GameManager> kirk;
        std::unique_ptr<Window> window;
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

    static Position startingTopLeftPosition;
};


#endif //TEXTBASED_GAME_H
