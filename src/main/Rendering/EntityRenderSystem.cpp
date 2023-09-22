#include "EntityRenderSystem.h"
#include "../HighLevel/ECSManager.h"
#include "../PositionsAndMovement/PositionComponent.h"
#include "../PositionsAndMovement/LiveComponent.h"

extern std::unique_ptr<ECSManager> ecsManager;

EntityRenderSystem::EntityRenderSystem() {
    requireComponent<PositionComponent>();
    requireComponent<TextComponent>();
    requireComponent<StyleComponent>();
    requireComponent<LiveComponent>();
}

void EntityRenderSystem::render(const std::shared_ptr<Renderer>& renderer, Camera camera){
    for (auto entity : getRelevantEntities()){
        auto& positionComponent = ecsManager->getComponentFromEntity<PositionComponent>(entity);
        const auto textComponent = ecsManager->getComponentFromEntity<TextComponent>(entity);
        const auto styleComponent = ecsManager->getComponentFromEntity<StyleComponent>(entity);
        renderer->renderText(camera, positionComponent.getPosition(), textComponent, styleComponent);
    }
}
