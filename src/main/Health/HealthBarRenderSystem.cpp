#include "HealthBarRenderSystem.h"
#include "../EventSystem/EventBus.h"
#include "../UIShow/HideHealthBarEvent.h"
#include "../UIShow/ShowHealthBarEvent.h"

extern std::unique_ptr<EventBus> eventBus;

void HealthBarRenderSystem::render(const std::shared_ptr<Renderer> &renderer, const HealthComponent &playerHealth) {
    if (!toRender) {
        return;
    }
    std::string renderedText;
    for(int x=0; x<playerHealth.health; x++){
        renderedText += heart;
    }
    renderer->renderFixedText(healthBarStartingPosition, TextComponent(renderedText), StyleComponent(Type::BRICOLEUR_TERMINAL_TEXT));
}

HealthBarRenderSystem::HealthBarRenderSystem() {
    eventBus->listenToEvent<HideHealthBarEvent>(this, &HealthBarRenderSystem::onHide);
    eventBus->listenToEvent<ShowHealthBarEvent>(this, &HealthBarRenderSystem::onShow);
}

void HealthBarRenderSystem::onHide(HideHealthBarEvent& event) {
    toRender = false;
}

void HealthBarRenderSystem::onShow(ShowHealthBarEvent& event) {
    toRender = true;
}


void HealthBarRenderSystem::render(const std::shared_ptr<Renderer> &renderer) {

}
