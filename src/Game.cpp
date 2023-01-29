#include "Game.h"
#include <SDL2/SDL.h>


void Game::initialize() {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
        return;
    }
    window = new Window();
    renderer = new Renderer(window);

    SDL_SetWindowFullscreen(window->getWindow(), SDL_WINDOW_FULLSCREEN);

    isRunning = true;
}

void Game::run() {
    Setup();
    while(isRunning){
        ProcessInput();
        Update();
        renderer->Render();
    }
}

void Game::Setup() {

}

void Game::ProcessInput() {
    SDL_Event sdlEvent;
    while (SDL_PollEvent(&sdlEvent)){
        switch(sdlEvent.type){
            case SDL_QUIT:
                isRunning = false;
                break;
            case SDL_KEYDOWN:
                if(sdlEvent.key.keysym.sym == SDLK_ESCAPE){
                    isRunning = false;
                }
                break;
        }
    }
}

void Game::Update() {

}

void Game::close() {
    delete renderer;
    delete window;
    SDL_Quit();
}
