#include "RenderSystem.h"

extern std::unique_ptr<ECSManager> manager;

RenderSystem::RenderSystem() {
    requireComponent<TransformComponent>();
    requireComponent<SpriteComponent>();
}

void RenderSystem::update(const std::shared_ptr<Renderer>& renderer){
    for (auto entity : getEntities()){
        spdlog::debug("Rendering entity " + std::to_string(entity.getId()));
        const auto positionComponent = manager->getComponent<TransformComponent>(entity);
        const auto spriteComponent = manager->getComponent<SpriteComponent>(entity);

        renderer->renderText(positionComponent.position, spriteComponent);
    }

    renderer->renderFrame();

}
