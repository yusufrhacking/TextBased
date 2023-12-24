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
        readTheText(entity, renderer);
    }
}

void NovelTextRenderSystem::readTheText(Entity entity, const std::shared_ptr<Renderer> &renderer) {
    auto positionComponent = ecsManager->getComponentFromEntity<PositionComponent>(entity);
    auto& textComponent = ecsManager->getComponentFromEntity<TextComponent>(entity);
    auto& novelTextComponent = ecsManager->getComponentFromEntity<NovelTextComponent>(entity);

    ensureTextIsLined(textComponent);
    skipReadingIfInstant(textComponent, novelTextComponent);

    auto currentTime = std::chrono::steady_clock::now();
    std::chrono::milliseconds timeDiff = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - lastUpdateTime);

    char newChar = textComponent.text[novelTextComponent.readIndex-1];

    if (isTimePassed(timeDiff) && isRoomInText(textComponent, novelTextComponent)) {
        novelTextComponent.readIndex++;
        lastUpdateTime = currentTime;
        trackSubject(novelTextComponent, newChar);
    }

    delayOnComma(newChar);

    std::string textToRender = textComponent.text.substr(0, novelTextComponent.readIndex);
    renderer->renderNovelText(positionComponent.getPosition(), TextComponent(textToRender), novelTextComponent);
}


void NovelTextRenderSystem::ensureTextIsLined(TextComponent& textComponent) {
    if (!textComponent.isLined) {
        textComponent.text = getLinedUpText(textComponent.text);
        textComponent.isLined = true;
    }
}

void NovelTextRenderSystem::skipReadingIfInstant(TextComponent& textComponent, NovelTextComponent& novelTextComponent) {
    if (standardTypingDelayMilliseconds == 0) {
        novelTextComponent.readIndex = textComponent.text.size();
    }
}

bool NovelTextRenderSystem::isTimePassed(std::chrono::milliseconds timeDiff) {
    return timeDiff.count() >= currentWaitingTime;
}

bool NovelTextRenderSystem::isRoomInText(TextComponent& textComponent, NovelTextComponent& novelTextComponent) {
    return novelTextComponent.readIndex < textComponent.text.size();
}

void NovelTextRenderSystem::trackSubject(NovelTextComponent& novelTextComponent, char newChar) {
    if (newChar == novelTextComponent.subject[subjectInd]) {
        if (subjectInd == 0) {
            startIndOfSubject = novelTextComponent.readIndex-1;
        }
        subjectInd++;
        if (subjectInd == novelTextComponent.subject.size()-1) {
            spdlog::info("Saint Teresa!");
            //activate mother teresa
        }
    } else {
        subjectInd = 0;
    }
}

void NovelTextRenderSystem::delayOnComma(char newChar) {
    if (newChar == ',') {
        currentWaitingTime = standardTypingDelayMilliseconds * COMMA_MULTIPLIER;
    } else {
        currentWaitingTime = standardTypingDelayMilliseconds;
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




