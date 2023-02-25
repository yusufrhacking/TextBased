#include "Game.h"
#include "ECS/Components/PositionComponent.h"
#include "ECS/Components/MovementComponent.h"
#include "ECS/Systems/MovementSystem.h"

Game::Game(ECSManager &manager) : manager(manager) {
    spdlog::info("Game object constructed");
    manager = ECSManager::getInstance();
}

void Game::initialize() {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
        spdlog::error("SDL INIT FAILED");
    }
    window = std::make_unique<Window>();
    renderer = std::make_unique<Renderer>(window->getWindow());
    inputProcessor = std::make_unique<InputProcessor>();

    isRunning = true;
}

void Game::setup() {
    manager.addSystem<MovementSystem>(manager);

    Entity tank = manager.createEntity();

    manager.addComponentToEntity<PositionComponent>(tank, std::make_shared<Position>(50, 50));
    manager.addComponentToEntity<MovementComponent>(tank, std::make_shared<Velocity>(1, 1));

    manager.removeComponent<PositionComponent>(tank);
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
    size_t timeToWait = MILLISECS_PER_FRAME - (SDL_GetTicks() - millisecsPreviousFrame);
    if (timeToWait > 0 && timeToWait <= MILLISECS_PER_FRAME) {
        SDL_Delay(timeToWait);
    }

    // The difference in ticks since the last frame, converted to seconds
    double deltaTime = (double)(SDL_GetTicks() - millisecsPreviousFrame) / 1000.0;

    // Store the "previous" frame time
    millisecsPreviousFrame = SDL_GetTicks();

    manager.getSystem<MovementSystem>().update();
    manager.update();
}

void Game::close() {
    SDL_Quit();
}

Game::~Game() {
    spdlog::info("Game destructor called");
}


