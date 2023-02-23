#include "Game.h"


void Game::initialize() {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
        spdlog::error("SDL INIT FAILED");
    }

    window = new Window();
    renderer = new Renderer(window);
    inputProcessor = new InputProcessor();
//    SDL_SetWindowSize(window->getWindow(), 1600, 1600);
    SDL_SetWindowFullscreen(window->getWindow(), SDL_WINDOW_FULLSCREEN);
    isRunning = true;
}

void Game::setup() {

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

}

void Game::close() {
    delete renderer;
    delete window;
    SDL_Quit();
}
