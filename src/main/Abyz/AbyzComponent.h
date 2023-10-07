#ifndef TEXTBASED_ABYZCOMPONENT_H
#define TEXTBASED_ABYZCOMPONENT_H

enum class AbyzState {
    IDLE,
    CHASE,
    ATTACK,
    COOLDOWN
};

struct AbyzComponent {
    float directionX{0.0f};
    float directionY{0.0f};
    float speed{25.0f};
    float attackCooldownRemaining = 0;
    AbyzState state{AbyzState::IDLE};

    AbyzComponent() = default;

    AbyzComponent(float dirX, float dirY, float spd)
            : directionX(dirX), directionY(dirY), speed(spd) {}
};


#endif
