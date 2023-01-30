#include "Game.h"


void Game::initialize() {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
        spdlog::error("SDL INIT FAILED");
    }

    window = new Window();
    renderer = new Renderer(window);
    inputProcessor = new InputProcessor();
    SDL_SetWindowFullscreen(window->getWindow(), SDL_WINDOW_FULLSCREEN);

    isRunning = true;
}

void Game::Setup() {

}

void Game::run() {
    Setup();
    while(isRunning){
        ProcessInput();
        Update();
        renderer->Render();
    }
}

void Game::ProcessInput() {
    SDL_Event sdlEvent;
    while (SDL_PollEvent(&sdlEvent)){
        isRunning = inputProcessor->ProcessInput(sdlEvent);
    }
}

void Game::Update() {

}

void Game::close() {
    delete renderer;
    delete window;
    SDL_Quit();
}
