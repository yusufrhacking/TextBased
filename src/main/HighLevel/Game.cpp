#include "Game.h"

Position Game::startingTopLeftPosition = {11760, 10516}; //Multiple of the frame height/width
int currFrame;

extern std::unique_ptr<ECSManager> ecsManager;

Game::Game(){
}

void Game::initialize() {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
        throw std::runtime_error("SDL Init Failed");
    }
    kirk = std::make_unique<GameManager>(Game::startingTopLeftPosition);
    inputProcessor = std::make_unique<InputProcessor>();
    SDL_StartTextInput();

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
        currFrame++;
    }
}

void Game::processInput() {
    isRunning = inputProcessor->processInput();
    // SDL_Event sdlEvent;
    // while (SDL_PollEvent(&sdlEvent)){
    //     spdlog::trace("Event polled");
    // }
}

void Game::update() {
    double deltaTime = waitForDeltaTime();
    spdlog::trace("Delta Time: {}", deltaTime);
    kirk->update(deltaTime);
}

void Game::render() {
    kirk->render();
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
    //log destructor called
}




