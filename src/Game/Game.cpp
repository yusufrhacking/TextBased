#include "Game.h"
#include "GameObjects/TextPerson.h"
#include "GameObjects/Mountain.h"
#include "GameObjects/Tree.h"
#include "TextGenerator.h"

std::unique_ptr<ECSManager> manager;
std::unique_ptr<Window> window;

Game::Game(){
    spdlog::debug("Game object constructed");
    manager = std::make_unique<ECSManager>();
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
    manager->addSystem<MovementSystem>();
    manager->addSystem<RenderSystem>();

    Entity tank = manager->createEntity();
    manager->addComponentToEntity<TransformComponent>(tank, std::make_shared<Position>(50, 50));
    manager->addComponentToEntity<MovementComponent>(tank, std::make_shared<Velocity>(20, 0));
    manager->addComponentToEntity<SpriteComponent>(tank, "Robert C. Martin");


    Entity json = manager->createEntity();
    manager->addComponentToEntity<TransformComponent>(json, std::make_shared<Position>(200, 200));
    manager->addComponentToEntity<MovementComponent>(json, std::make_shared<Velocity>(0, -18));
    manager->addComponentToEntity<SpriteComponent>(json, "Jaeson Martin");

    Entity tree = manager->createEntity();
    manager->addComponentToEntity<TransformComponent>(tree, window->getTopLeftPosition());
    manager->addComponentToEntity<SpriteComponent>(tree, TextGenerator::getTreeText());

    auto sprite = manager->getComponent<SpriteComponent>(tree);


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
    manager->update(deltaTime);
}

void Game::render() {
    manager->render(renderer);
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




