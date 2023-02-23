#include "Window.h"
#include <SDL2/SDL.h>
#include <spdlog/spdlog.h>

Window::Window() {
    SDL_DisplayMode displayMode;
    SDL_GetCurrentDisplayMode(0, &displayMode);
    windowWidth = 1200;
    windowHeight = 900;

    window = SDL_CreateWindow(
            nullptr,
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            windowWidth,
            windowHeight,
            0
    );

    if (window == NULL){
        spdlog::error("Window initialization failed");
    }
}

SDL_Window *Window::getWindow() {
    return window;
}


