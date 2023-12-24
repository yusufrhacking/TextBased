#include "NovelTextRenderSystem.h"
#include "../PositionsAndMovement/PositionComponent.h"
#include "../HighLevel/ECSManager.h"

extern std::unique_ptr<ECSManager> ecsManager;

NovelTextRenderSystem::NovelTextRenderSystem() {
    requireComponent<TextComponent>();
    requireComponent<NovelTextComponent>();
    requireComponent<PositionComponent>();

    lastUpdateTime = std::chrono::steady_clock::now();
}

void NovelTextRenderSystem::render(const std::shared_ptr<Renderer> &renderer) {
    //Need to make it render character by character now!
    //Store the character position in the novel text component
    for (auto entity : getRelevantEntities()) {
        auto positionComponent = ecsManager->getComponentFromEntity<PositionComponent>(entity);
        auto& textComponent = ecsManager->getComponentFromEntity<TextComponent>(entity);
        auto& novelTextComponent = ecsManager->getComponentFromEntity<NovelTextComponent>(entity);

        if (!textComponent.isLined) {
            textComponent.text = getLinedUpText(textComponent.text);
            textComponent.isLined = true;
        }

        if (typingDelayMilliseconds == 0) {
            novelTextComponent.readIndex = textComponent.text.size();
        }

        auto currentTime = std::chrono::steady_clock::now();
        auto timeDiff = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - lastUpdateTime);

        if (timeDiff.count() >= typingDelayMilliseconds && novelTextComponent.readIndex < textComponent.text.size()) {
            novelTextComponent.readIndex++;
            lastUpdateTime = currentTime;
        }

        std::string textToRender = textComponent.text.substr(0, novelTextComponent.readIndex);
        renderer->renderNovelText(positionComponent.getPosition(), TextComponent(textToRender), novelTextComponent);
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



