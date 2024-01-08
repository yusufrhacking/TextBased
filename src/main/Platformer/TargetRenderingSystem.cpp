#include "TargetRenderingSystem.h"

#include "TargetComponent.h"
#include "../HighLevel/ECSManager.h"
#include "../PositionsAndMovement/PositionComponent.h"
#include "../PositionsAndMovement/LiveComponent.h"

extern std::unique_ptr<ECSManager> ecsManager;

TargetRenderingSystem::TargetRenderingSystem() {
    requireComponent<PositionComponent>();
    requireComponent<TextComponent>();
    requireComponent<TargetComponent>();
    requireComponent<LiveComponent>();
}

void TargetRenderingSystem::render(const std::shared_ptr<Renderer>& renderer, Camera camera){
    for (auto entity : getRelevantEntities()){
        auto& positionComponent = ecsManager->getComponentFromEntity<PositionComponent>(entity);
        const auto textComponent = ecsManager->getComponentFromEntity<TextComponent>(entity);
        renderer->renderDynamicText(camera, positionComponent.getPosition(), textComponent, GenericStyleComponent(RenderStyle::GOLD));
    }
}