#include "RenderSystem.h"

extern std::unique_ptr<ECSManager> ecsManager;

RenderSystem::RenderSystem() {
    requireComponent<PositionComponent>();
    requireComponent<TextComponent>();
    requireComponent<StyleComponent>();
}

void RenderSystem::update(const std::shared_ptr<Renderer>& renderer){
    for (auto entity : getRelevantEntities()){
        const auto positionComponent = ecsManager->getComponentFromEntity<PositionComponent>(entity);
        const auto spriteComponent = ecsManager->getComponentFromEntity<TextComponent>(entity);
        const auto styleComponent = ecsManager->getComponentFromEntity<StyleComponent>(entity);

        renderer->renderText(positionComponent.position, spriteComponent, styleComponent);
    }

    renderer->renderFrame();

}
