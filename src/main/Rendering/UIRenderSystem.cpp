#include "UIRenderSystem.h"
#include "../EventSystem/EventBus.h"

extern std::unique_ptr<EventBus> eventBus;

UIRenderSystem::UIRenderSystem(std::shared_ptr<Renderer>& renderer) {
    this->renderer = renderer;
    listenToEvents();
}

void UIRenderSystem::listenToEvents() {
    eventBus->listenToEvent<TextQueuedEvent>(this, &UIRenderSystem::onTextQueuedEvent);
}

void UIRenderSystem::onTextQueuedEvent(TextQueuedEvent& event) {
    renderer->renderTerminal(event.text);
}
