#ifndef TEXTBASED_ABYZCOMPONENT_H
#define TEXTBASED_ABYZCOMPONENT_H

struct AbyzComponent {
    float directionX{0.0f};
    float directionY{0.0f};
    float speed{1.0f};

    AbyzComponent() = default;

    AbyzComponent(float dirX, float dirY, float spd)
            : directionX(dirX), directionY(dirY), speed(spd) {}
};


#endif
