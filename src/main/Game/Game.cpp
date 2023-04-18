#include "Game.h"
#include "TextGenerator.h"

std::unique_ptr<ECSManager> ecsManager;
std::unique_ptr<Window> window;

Game::Game(){
    spdlog::debug("Game object constructed");
    ecsManager = std::make_unique<ECSManager>();
}

void Game::initialize() {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
        spdlog::error("SDL INIT FAILED");
    }

    window = std::make_unique<Window>();
    renderer = std::make_shared<Renderer>(window->getWindow());
    inputProcessor = std::make_unique<InputProcessor>();

    isRunning = true;
}

void Game::setup() {
    kirk->setup();
}

void Game::run() {
    setup();
    while(isRunning){
        processInput();
        update();
        render();
    }
}

void Game::processInput() {
    SDL_Event sdlEvent;
    while (SDL_PollEvent(&sdlEvent)){
        isRunning = inputProcessor->processInput(sdlEvent);
    }
}

void Game::update() {
    double deltaTime = waitForDeltaTime();
    ecsManager->update(deltaTime);
}

void Game::render() {
    ecsManager->render(renderer);
}

double Game::waitForDeltaTime() {
    size_t timeToWait = MILLISECS_PER_FRAME - (SDL_GetTicks() - millisecsPreviousFrame);
    if (timeToWait > 0 && timeToWait <= MILLISECS_PER_FRAME) {
        SDL_Delay(timeToWait);
    }

    // The difference in ticks since the last frame, converted to seconds
    double deltaTime = (double)(SDL_GetTicks() - millisecsPreviousFrame) / 1000.0;

    // Store the "previous" frame time
    millisecsPreviousFrame = SDL_GetTicks();
    return deltaTime;
}

void Game::close() {
    SDL_Quit();
}

Game::~Game() {
    spdlog::info("Game destructor called");
}



