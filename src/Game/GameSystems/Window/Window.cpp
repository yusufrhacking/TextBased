#include "Window.h"
#include <SDL2/SDL.h>
#include <spdlog/spdlog.h>

Window::Window() {
    createWindow();
}

Window::~Window() {
    SDL_DestroyWindow(window);
}


void Window::createWindow() {
    SDL_DisplayMode displayMode;
    SDL_GetCurrentDisplayMode(0, &displayMode);
    windowWidth = displayMode.w;
    windowHeight = displayMode.h;

    window = SDL_CreateWindow(
            nullptr,
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            windowWidth,
            windowHeight,
            0
    );

    if (window == nullptr){
        spdlog::error("Window initialization failed");
    }
}


SDL_Window *Window::getWindow() {
    return window;
}



