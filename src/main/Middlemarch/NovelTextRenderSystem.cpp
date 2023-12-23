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
    for (auto entity : getRelevantEntities()) {
        auto positionComponent = ecsManager->getComponentFromEntity<PositionComponent>(entity);
        auto textComponent = ecsManager->getComponentFromEntity<TextComponent>(entity);
        auto novelTextComponent = ecsManager->getComponentFromEntity<NovelTextComponent>(entity);


        std::string linedUpText = getLinedUpText(textComponent);
        textComponent.text = linedUpText;
        renderer->renderNovelText(positionComponent.getPosition(), textComponent, novelTextComponent);
    }
}

std::string NovelTextRenderSystem::getLinedUpText(const TextComponent& textComponent){
    const int maxLineWidth = Window::windowWidth;
    std::string finalText;
    std::istringstream charStream(textComponent.text);
    std::string word;
    int currentLineWidth = 0;
    char ch;

    while (charStream.get(ch)) {
        if (ch != ' ') {
            word += ch;
        }

        if (ch == ' ' || charStream.peek() == EOF) {
            int wordWidth = word.length() * MONACO_RENDERED_TEXT_WIDTH_SCALER;

            if (currentLineWidth + wordWidth > maxLineWidth) {
                finalText += "\n";
                currentLineWidth = 0;
            }

            finalText += word + (ch == ' ' ? " " : "");
            currentLineWidth += wordWidth + (ch == ' ' ? MONACO_RENDERED_TEXT_WIDTH_SCALER : 0);
            word.clear();
        }
    }
    return finalText;
}




