#ifndef SPAWNABYZCOMPONENT_H
#define SPAWNABYZCOMPONENT_H

struct SpawnAbyzComponent {
    std::chrono::steady_clock::time_point lastUpdateTime = std::chrono::steady_clock::now();
    SpawnAbyzComponent() = default;
};

#endif //SPAWNABYZCOMPONENT_H
