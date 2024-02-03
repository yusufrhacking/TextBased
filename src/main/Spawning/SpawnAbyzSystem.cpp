#include "SpawnAbyzSystem.h"

#include "../Abyz/PlainAbyzPrefab.h"
#include "../PositionsAndMovement/PositionComponent.h"
#include "../HighLevel/ECSManager.h"

extern std::unique_ptr<ECSManager> ecsManager;

SpawnAbyzSystem::SpawnAbyzSystem() {
    requireComponent<SpawnAbyzSystem>();
    requireComponent<PositionComponent>();
    requireComponent<TextComponent>();
}

void SpawnAbyzSystem::update(double deltaTime) {
    for(auto entity: getRelevantEntities()) {
        auto abyzPosition = ecsManager->getComponentFromEntity<PositionComponent>(entity).getPosition();
        auto surfaceSize = ecsManager->getComponentFromEntity<TextComponent>(entity).getSurfaceSize();
        abyzPosition.y += static_cast<float>(surfaceSize.height);

        Entity abyz = ecsManager->createEntity();
        ecsManager->addComponentToEntity<TextComponent>(abyz, "Abyz");
        ecsManager->addComponentToEntity<PositionComponent>(abyz, abyzPosition);
        ecsManager->addComponentToEntity<LiveComponent>(abyz);
        ecsManager->addComponentToEntity<AbyzComponent>(abyz);
    }
}
