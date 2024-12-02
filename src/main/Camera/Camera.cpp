#include "Camera.h"
#include "../Rendering/Window.h"

Camera::Camera(Position startingPosition) {
    camera.x = (int)startingPosition.x;
    camera.y = (int)startingPosition.y;
    camera.w = Window::windowWidth;
    camera.h = Window::windowHeight;
}

void Camera::positionCamera(Position position) {
    camera.x = (int)position.x;
    camera.y = (int)position.y;
}

Position Camera::getCameraPosition() const {
    auto xPos = (float)camera.x;
    auto yPos = (float)camera.y;
    return {xPos, yPos};

}

