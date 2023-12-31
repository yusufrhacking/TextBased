#include "AbyzRunningSystem.h"

AbyzRunningSystem::AbyzRunningSystem() {
    requireComponent<WordRelicComponent>();
    requireComponent<PositionComponent>();
    requireComponent<LiveComponent>();
    requireComponent<TextComponent>();
}

void AbyzRunningSystem::update(double deltaTime) {
}
