#include "RenderSystem.h"

extern std::unique_ptr<ECSManager> ecsManager;

RenderSystem::RenderSystem() {
    requireComponent<PositionComponent>();
    requireComponent<TextComponent>();
    requireComponent<StyleComponent>();
}

void RenderSystem::update(const std::shared_ptr<Renderer>& renderer){
    for (auto entity : getReleventEntities()){
        const auto positionComponent = ecsManager->getComponent<PositionComponent>(entity);
        const auto spriteComponent = ecsManager->getComponent<TextComponent>(entity);
        const auto styleComponent = ecsManager->getComponent<StyleComponent>(entity);

        renderer->renderText(positionComponent.position, spriteComponent, styleComponent);
    }

    renderer->renderFrame();

}
