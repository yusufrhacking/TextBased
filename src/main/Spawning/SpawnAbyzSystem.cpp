#include "SpawnAbyzSystem.h"

#include "SpawnAbyzComponent.h"
#include "../Abyz/LifeGateComponent.h"
#include "../Abyz/PlainAbyzPrefab.h"
#include "../Gravity/GravityComponent.h"
#include "../PositionsAndMovement/PositionComponent.h"
#include "../HighLevel/ECSManager.h"
#include "../Platformer/HorizontalPlatformMovementComponent.h"
#include "../PositionsAndMovement/VelocityComponent.h"

extern std::unique_ptr<ECSManager> ecsManager;

SpawnAbyzSystem::SpawnAbyzSystem() {
    requireComponent<SpawnAbyzComponent>();
    requireComponent<PositionComponent>();
    requireComponent<TextComponent>();
}

void SpawnAbyzSystem::spawnAbyz(std::set<Entity>::value_type entity) {
    auto abyzPosition = ecsManager->getComponentFromEntity<PositionComponent>(entity).getPosition();
    auto surfaceSize = ecsManager->getComponentFromEntity<TextComponent>(entity).getSurfaceSize();
    abyzPosition.y += static_cast<float>(surfaceSize.height);
    abyzPosition.x += ecsManager->getComponentFromEntity<TextComponent>(entity).getSurfaceSize().width/2 - TextComponent::getSurfaceSize("Abyz").width/2;

    Entity abyz = ecsManager->createEntity();
    ecsManager->addComponentToEntity<TextComponent>(abyz, "Abyz");
    ecsManager->addComponentToEntity<PositionComponent>(abyz, abyzPosition);
    ecsManager->addComponentToEntity<LiveComponent>(abyz);
    ecsManager->addComponentToEntity<AbyzComponent>(abyz);
    ecsManager->addComponentToEntity<GravityComponent>(abyz);
    ecsManager->addComponentToEntity<VelocityComponent>(abyz);
    ecsManager->addComponentToEntity<LifeGateComponent>(abyz, abyzPosition.y + Window::windowHeight);
    ecsManager->addComponentToEntity<CollisionComponent>(abyz);
    ecsManager->addComponentToEntity<HorizontalPlatformMovementComponent>(abyz);
}

void SpawnAbyzSystem::update(double deltaTime) {
    for(auto entity: getRelevantEntities()) {
        auto& spawner = ecsManager->getComponentFromEntity<SpawnAbyzComponent>(entity);

        auto currentTime = std::chrono::steady_clock::now();
        std::chrono::milliseconds timeDiff = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - spawner.lastUpdateTime);

        if (timeDiff.count() >= currentWaitingTimeMilliseconds) {
            spawnAbyz(entity);
            spawner.lastUpdateTime = std::chrono::steady_clock::now();
        }
    }
}
