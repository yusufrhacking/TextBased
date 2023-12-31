#include "AbyzRenderingSystem.h"
#include "../HighLevel/ECSManager.h"
#include "../PositionsAndMovement/PositionComponent.h"
#include "../PositionsAndMovement/LiveComponent.h"

#include "AbyzComponent.h"
extern std::unique_ptr<ECSManager> ecsManager;
AbyzRenderingSystem::AbyzRenderingSystem() {
    requireComponent<PositionComponent>();
    requireComponent<TextComponent>();
    requireComponent<AbyzComponent>();
    requireComponent<LiveComponent>();
}

void AbyzRenderingSystem::render(const std::shared_ptr<Renderer>& renderer, Camera camera) {
    for (auto entity : getRelevantEntities()){
        auto& positionComponent = ecsManager->getComponentFromEntity<PositionComponent>(entity);
        const auto textComponent = ecsManager->getComponentFromEntity<TextComponent>(entity);
        renderer->renderDynamicText(camera, positionComponent.getPosition(), textComponent, GenericStyleComponent(RenderStyle::RED));
    }
}
