#include "RenderSystem.h"
#include "../HighLevel/ECSManager.h"
#include "../PositionsAndMovement/PositionComponent.h"

extern std::unique_ptr<ECSManager> ecsManager;

RenderSystem::RenderSystem() {
    requireComponent<PositionComponent>();
    requireComponent<TextComponent>();
    requireComponent<StyleComponent>();
}

void RenderSystem::render(const std::shared_ptr<Renderer>& renderer, Camera camera){
    for (auto entity : getRelevantEntities()){
        auto& positionComponent = ecsManager->getComponentFromEntity<PositionComponent>(entity);
        const auto spriteComponent = ecsManager->getComponentFromEntity<TextComponent>(entity);
        const auto styleComponent = ecsManager->getComponentFromEntity<StyleComponent>(entity);

        renderer->renderText(camera, positionComponent.getPosition(), spriteComponent, styleComponent);
    }

    renderer->renderFrame();

}