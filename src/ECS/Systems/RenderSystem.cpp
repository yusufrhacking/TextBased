#include "RenderSystem.h"

extern std::unique_ptr<ECSManager> manager;

RenderSystem::RenderSystem() {
    requireComponent<PositionComponent>();
    requireComponent<SpriteComponent>();
}

void RenderSystem::update(const std::shared_ptr<Renderer>& renderer){
    for (auto entity : getEntities()){
        const auto positionComponent = manager->getComponent<PositionComponent>(entity);
        const auto spriteComponent = manager->getComponent<SpriteComponent>(entity);

        renderer->renderText(positionComponent.position, spriteComponent);
    }

    renderer->render();

}
