#include "RenderSystem.h"

extern std::unique_ptr<ECSManager> manager;

RenderSystem::RenderSystem() {
    requireComponent<PositionComponent>();
    requireComponent<SpriteComponent>();
}

void RenderSystem::update(std::shared_ptr<Renderer> renderer){
    for (auto entity : getEntities()){
        const auto positionComponent = manager->getComponent<PositionComponent>(entity);
        const auto spriteComponent = manager->getComponent<SpriteComponent>(entity);

        auto text = spriteComponent.text;
        auto width = spriteComponent.width;
        auto height = spriteComponent.height;

        auto xPos = positionComponent.position->xPos;
        auto yPos = positionComponent.position->yPos;


    }
}
