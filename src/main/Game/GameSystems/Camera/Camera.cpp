#include "Camera.h"
#include "../Window/Window.h"

Camera::Camera(Position startingPosition) {
    camera.x = 0;
    camera.y = 0;
    camera.w = Window::windowWidth;
    camera.h = Window::windowHeight;
}

void Camera::positionCamera(Position position) {
    camera.x = (int)position.xPos;
    camera.y = (int)position.yPos;
}

Position Camera::getCameraPosition() {
    auto xPos = (float)camera.x;
    auto yPos = (float)camera.y;
    return {xPos, yPos};

}

