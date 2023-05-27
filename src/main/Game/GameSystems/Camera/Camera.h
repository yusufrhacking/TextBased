#ifndef TEXTBASED_CAMERA_H
#define TEXTBASED_CAMERA_H


#include <SDL_rect.h>
#include "../../../Helpers/Objects/Position.h"

class Camera {
private:
    SDL_Rect camera;
public:
    explicit Camera(Position startingPosition);

    void positionCamera(Position position);

    Position getCameraPosition();
};


#endif //TEXTBASED_CAMERA_H
