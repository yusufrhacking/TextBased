#include "Game.h"
#include "GameSystems/Renderer/SDLRenderer.h"
#include "TextGenerator.h"
#include <stdexcept>
#include "spdlog/spdlog.h"

Position Game::startingTopLeftPosition = {11760, 10516};
int currFrame;

Game::Game(){
}

void Game::initialize() {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
        throw std::runtime_error("SDL Init Failed");
    }
    window = std::make_unique<Window>();
    renderer = std::make_shared<SDLRenderer>(window->getWindow());
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
        currFrame++;
    }
}

void Game::processInput() {
    SDL_Event sdlEvent;
    while (SDL_PollEvent(&sdlEvent)){
        spdlog::trace("Event polled");
        isRunning = inputProcessor->processInput(sdlEvent);
    }
}

void Game::update() {
    double deltaTime = waitForDeltaTime();
    spdlog::trace("Delta Time: {}", deltaTime);
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
    //log destructor called
}




