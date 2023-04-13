#include "RenderSystem.h"

extern std::unique_ptr<ECSManager> ecsManager;

RenderSystem::RenderSystem() {
    requireComponent<TransformComponent>();
    requireComponent<SpriteComponent>();
}

void RenderSystem::update(const std::shared_ptr<Renderer>& renderer){
    for (auto entity : getReleventEntities()){
        spdlog::debug("Rendering entity " + std::to_string(entity.getId()));
        const auto positionComponent = ecsManager->getComponent<TransformComponent>(entity);
        const auto spriteComponent = ecsManager->getComponent<SpriteComponent>(entity);

        renderer->renderText(positionComponent.position, spriteComponent);
    }

    renderer->renderFrame();

}
