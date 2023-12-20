#include "MainPlayerAccessSystem.h"

MainPlayerAccessSystem::MainPlayerAccessSystem() {
    requireComponent<MainPlayerComponent>();
}

bool MainPlayerAccessSystem::hasMainPlayer() {
    return !getRelevantEntities().empty();
}

Entity MainPlayerAccessSystem::getMainPlayer() {
    if (!hasMainPlayer()){
        throw std::runtime_error("No main player!");
    }
    return *getRelevantEntities().begin();
}
