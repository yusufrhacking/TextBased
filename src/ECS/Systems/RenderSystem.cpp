#include "RenderSystem.h"

extern std::unique_ptr<ECSManager> ecsManager;

RenderSystem::RenderSystem() {
    requireComponent<PositionComponent>();
    requireComponent<TextComponent>();
    requireComponent<ShowComponent>();
}

void RenderSystem::update(const std::shared_ptr<Renderer>& renderer){
    for (auto entity : getReleventEntities()){
        spdlog::debug("Rendering entity " + std::to_string(entity.getId()));
        const auto positionComponent = ecsManager->getComponent<PositionComponent>(entity);
        const auto spriteComponent = ecsManager->getComponent<TextComponent>(entity);

        renderer->renderText(positionComponent.position, spriteComponent);
    }

    renderer->renderFrame();

}
