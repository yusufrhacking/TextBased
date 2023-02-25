#include "Game.h"
#include "ECS/Components/PositionComponent.h"
#include "ECS/Components/MovementComponent.h"

Game::Game(){
    spdlog::info("Game object constructed");
}

void Game::initialize() {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
        spdlog::error("SDL INIT FAILED");
    }
    window = std::make_unique<Window>();
    renderer = std::make_unique<Renderer>(window->getWindow());
    inputProcessor = std::make_unique<InputProcessor>();
    manager = std::make_unique<ECSManager>();

    isRunning = true;
}

void Game::setup() {
    Entity tank = manager->createEntity();

    manager->addComponentToEntity<PositionComponent>(tank, std::make_shared<Position>());
    manager->addComponentToEntity<MovementComponent>(tank, std::make_shared<Velocity>());
}

void Game::run() {
    setup();
    while(isRunning){
        processInput();
        update();
        renderer->render();
    }
}

void Game::processInput() {
    SDL_Event sdlEvent;
    while (SDL_PollEvent(&sdlEvent)){
        isRunning = inputProcessor->processInput(sdlEvent);
    }
}

void Game::update() {
    manager->update();
}

void Game::close() {
    SDL_Quit();
}

Game::~Game() {
    spdlog::info("Game destructor called");
}


