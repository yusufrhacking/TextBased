#include "NovelTextRenderSystem.h"
#include "../PositionsAndMovement/PositionComponent.h"
#include "../HighLevel/ECSManager.h"

extern std::unique_ptr<ECSManager> ecsManager;

NovelTextRenderSystem::NovelTextRenderSystem() {
    requireComponent<TextComponent>();
    requireComponent<NovelTextComponent>();
    requireComponent<PositionComponent>();
}

void NovelTextRenderSystem::render(const std::shared_ptr<Renderer> &renderer) {
    for(auto entity: getRelevantEntities()){
        auto positionComponent = ecsManager->getComponentFromEntity<PositionComponent>(entity);
        auto textComponent = ecsManager->getComponentFromEntity<TextComponent>(entity);
        auto novelTextComponent = ecsManager->getComponentFromEntity<NovelTextComponent>(entity);

        int lineLength = Window::windowWidth;
        const std::string& text = textComponent.text;
        std::string finalText;
        for(size_t i = 0; i < text.size(); i++){
            lineLength -= MONACO_RENDERED_TEXT_WIDTH_SCALER;
            if(lineLength <= 0){
                finalText += "\n";
                lineLength = Window::windowWidth;
            }
            finalText += text[i];
        }

        textComponent.text = finalText;
        renderer->renderNovelText(positionComponent.getPosition(), textComponent, novelTextComponent);

        //Need to figure out when it gets to the side of the page
        //Need to somehow make it seem like reading
    }
}


