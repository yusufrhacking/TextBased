#include "HealthBarRenderSystem.h"

void HealthBarRenderSystem::render(const std::shared_ptr<Renderer> &renderer, const HealthComponent &playerHealth) {
    std::string renderedText;
    for(int x=0; x<playerHealth.health; x++){
        renderedText += heart;
    }
    renderer->renderFixedText(healthBarStartingPosition, TextComponent(renderedText), StyleComponent(Type::PLAIN_TEXT));
}

void HealthBarRenderSystem::render(const std::shared_ptr<Renderer> &renderer) {

}
