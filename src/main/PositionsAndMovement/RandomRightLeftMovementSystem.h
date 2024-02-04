#ifndef RANDOMRIGHTLEFTMOVEMENTSYSTEM_H
#define RANDOMRIGHTLEFTMOVEMENTSYSTEM_H
#include <random>
#include <chrono>

#include "RandomRightLeftMovementComponent.h"
#include "../ECSObjects/UpdateSystem.h"


class RandomRightLeftMovementSystem: public UpdateSystem {
    double timeBeforeSwapinSec = 2;
    std::mt19937 rng;

    int generateRandomDirection() {
        std::uniform_int_distribution<int> dist(-1, 1);
        int direction = 0;
        while (direction == 0) {
            direction = dist(rng);
        }
        return direction;
    }

    void swapDirection(std::chrono::steady_clock::time_point now, RandomRightLeftMovementComponent& movementComponent);

public:
    RandomRightLeftMovementSystem();
    void update(double deltaTime) override;

};



#endif //RANDOMRIGHTLEFTMOVEMENTSYSTEM_H
