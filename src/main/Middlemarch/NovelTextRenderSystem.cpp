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


        std::string linedUpText = getLinedUpText(textComponent.text);
        textComponent.text = linedUpText;
        renderer->renderNovelText(positionComponent.getPosition(), textComponent, novelTextComponent);
    }
}

std::string NovelTextRenderSystem::getLinedUpText(const std::string& text) {
    double characterLength = MONACO_RENDERED_TEXT_WIDTH_SCALER;
    double lineCapacity = Window::windowWidth / characterLength;

    std::stringstream finalTextStream;
    std::stringstream wordStream;
    double currentLength = 0;

    for (char ch : text) {
        if (!(ch == ' ' || ch == '\n')) {
            wordStream << ch;
        } else {
            std::string word = wordStream.str();
            double wordLength = word.length();

            if (currentLength + wordLength > lineCapacity) {
                finalTextStream << "\n";
                currentLength = 0;
            }

            finalTextStream << word << (ch == ' ' ? " " : "\n");
            wordStream.str("");
            wordStream.clear();
            currentLength += wordLength + 1;
        }
    }

    if (!wordStream.str().empty()) {
        if (currentLength + wordStream.str().length() > lineCapacity) {
            finalTextStream << "\n";
        }
        finalTextStream << wordStream.str();
    }

    return finalTextStream.str();
}




