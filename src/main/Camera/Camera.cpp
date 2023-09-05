#include "Camera.h"
#include "../Rendering/Window.h"

Camera::Camera(Position startingPosition) {
    camera.x = (int)startingPosition.xPos;
    camera.y = (int)startingPosition.yPos;
    camera.w = Window::windowWidth;
    camera.h = Window::windowHeight;
}

void Camera::positionCamera(Position position) {
    camera.x = (int)position.xPos;
    camera.y = (int)position.yPos;
}

Position Camera::getCameraPosition() const {
    auto xPos = (float)camera.x;
    auto yPos = (float)camera.y;
    return {xPos, yPos};

}

