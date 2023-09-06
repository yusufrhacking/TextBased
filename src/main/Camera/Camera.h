#ifndef TEXTBASED_CAMERA_H
#define TEXTBASED_CAMERA_H
#include <SDL_rect.h>
#include "../PositionsAndMovement/Position.h"

class Camera {
private:
    SDL_Rect camera{};
public:
    explicit Camera(Position startingPosition);

    void positionCamera(Position position);

    [[nodiscard]] Position getCameraPosition() const;
};


#endif //TEXTBASED_CAMERA_H
