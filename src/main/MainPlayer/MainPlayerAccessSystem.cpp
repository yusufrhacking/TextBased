#include "MainPlayerAccessSystem.h"

MainPlayerAccessSystem::MainPlayerAccessSystem() {
    requireComponent<MainPlayerComponent>();
}

Entity MainPlayerAccessSystem::getMainPlayer() {
    return *getRelevantEntities().begin();
}
