#pragma clang diagnostic push
#pragma ide diagnostic ignored "cppcoreguidelines-pro-type-member-init"
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
        spdlog::error(SDL_GetError());
    }
}


SDL_Window *Window::getWindow() {
    return window;
}

int Window::getWindowWidth() {
    return windowWidth;
}

int Window::getWindowHeight() {
    return windowHeight;
}

Position Window::getTopLeftPosition() const {
    Position TOP_LEFT_POSITION = {0, 0};
    return TOP_LEFT_POSITION;
}

Position Window::getBottomLeftPosition() const {
    Position BOTTOM_LEFT_POSITION = {0, static_cast<float>(windowHeight)};
    return BOTTOM_LEFT_POSITION;
}

Position Window::getTopRightPosition() const {
    Position TOP_RIGHT_POSITION = {static_cast<float>(windowWidth), 0};
    return TOP_RIGHT_POSITION;
}

Position Window::getBottomRightPosition() const {
    Position BOTTOM_RIGHT_POSITION = {static_cast<float>(windowWidth), static_cast<float>(windowHeight)};
    return BOTTOM_RIGHT_POSITION;
}


#pragma clang diagnostic pop