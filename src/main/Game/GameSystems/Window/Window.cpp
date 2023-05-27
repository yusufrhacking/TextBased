#pragma clang diagnostic push
#pragma ide diagnostic ignored "cppcoreguidelines-pro-type-member-init"
#include "Window.h"
#include <SDL.h>
#include <stdexcept>

int Window::windowWidth = 0;
int Window::windowHeight = 0;

Window::Window() {
    createWindow();
}

Window::~Window() {
    SDL_DestroyWindow(window);
}


void Window::createWindow() {
    initializeWindowSize();
    window = SDL_CreateWindow(
            nullptr,
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            windowWidth,
            windowHeight,
            0
    );

    if (window == nullptr){
        throw std::runtime_error(SDL_GetError());
    }

    camera.x = 0;
    camera.y = 0;
    camera.w = windowWidth;
    camera.h = windowHeight;
}


SDL_Window *Window::getWindow() {
    return window;
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

void Window::positionCamera(Position position) {
    camera.x = (int)position.xPos;
    camera.y = (int)position.yPos;
}

Position Window::getCameraPosition() {
    auto xPos = (float)camera.x;
    auto yPos = (float)camera.y;
    return {xPos, yPos};
}

Position Window::getMiddlePosition() {
    Position MIDDLE = {static_cast<float>(windowWidth)/2, static_cast<float>(windowHeight)/2};
    return MIDDLE;
}

void Window::initializeWindowSize() {
    if (windowWidth == 0 || windowHeight == 0) {
        SDL_DisplayMode displayMode;
        SDL_GetCurrentDisplayMode(0, &displayMode);
        windowWidth = displayMode.w;
        windowHeight = displayMode.h;
    }
}


#pragma clang diagnostic pop