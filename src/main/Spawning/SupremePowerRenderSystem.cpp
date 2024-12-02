#include "SupremePowerRenderSystem.h"
#include "../HighLevel/ECSManager.h"
#include "../PositionsAndMovement/PositionComponent.h"
#include "../PositionsAndMovement/LiveComponent.h"
#include "SupremePowerComponent.h"

extern std::unique_ptr<ECSManager> ecsManager;

SupremePowerRenderSystem::SupremePowerRenderSystem() {
    requireComponent<PositionComponent>();
    requireComponent<TextComponent>();
    requireComponent<SupremePowerComponent>();
    requireComponent<LiveComponent>();
}

void SupremePowerRenderSystem::render(const std::shared_ptr<Renderer>& renderer, Camera camera){
    for (auto entity : getRelevantEntities()){
        auto& positionComponent = ecsManager->getComponentFromEntity<PositionComponent>(entity);
        const auto textComponent = ecsManager->getComponentFromEntity<TextComponent>(entity);
        renderer->renderDynamicText(camera, positionComponent.getPosition(), textComponent, GenericStyleComponent(RenderStyle::AMBER_TERMINAL));
    }
}