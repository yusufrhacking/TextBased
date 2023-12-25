#include "NovelTextRenderSystem.h"
#include "../PositionsAndMovement/PositionComponent.h"
#include "../HighLevel/ECSManager.h"
#include "../PositionsAndMovement/LiveComponent.h"
#include "../Text/Split.h"

extern std::unique_ptr<ECSManager> ecsManager;

NovelTextRenderSystem::NovelTextRenderSystem() {
    requireComponent<TextComponent>();
    requireComponent<NovelTextComponent>();
    requireComponent<PositionComponent>();

    lastUpdateTime = std::chrono::steady_clock::now();
}

void NovelTextRenderSystem::render(const std::shared_ptr<Renderer> &renderer, Camera camera) {
    //Need to make it render character by character now!
    //Store the character position in the novel text component
    for (auto entity : getRelevantEntities()) {
        readTheText(entity, renderer, camera);
    }
}

void NovelTextRenderSystem::readTheText(Entity entity, const std::shared_ptr<Renderer> &renderer, Camera camera) {
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
    renderer->renderDynamicText(camera, positionComponent.getPosition(), TextComponent(textToRender), GenericStyleComponent());

    if (novelTextComponent.readIndex == textComponent.text.size()-1) {
        auto words = Split::getWords(textComponent.text);
        Position currPosition = positionComponent.getPosition();
        for (auto word: words) {
            // word.erase(std::remove_if(word.begin(), word.end(), [](char c) {
            // return c == ',' || c == '.';}), word.end());

            Entity wordEntity = ecsManager->createEntity();
            ecsManager->addComponentToEntity<PositionComponent>(wordEntity, currPosition);
            ecsManager->addComponentToEntity<TextComponent>(wordEntity, word);
            ecsManager->addComponentToEntity<GenericStyleComponent>(wordEntity);
            ecsManager->addComponentToEntity<LiveComponent>(wordEntity);

            if (word.find('\n') != std::string::npos) {
                currPosition.xPos = currPosition.xPos - (currPosition.xPos - Window::windowWidth);
                currPosition.yPos -= MONACO_HEIGHT_OF_A_LINE_OF_TEXT;
                spdlog::info("New Line!");
            } else {
                currPosition += Position(word.size() * MONACO_RENDERED_TEXT_WIDTH_SCALER, 0);
            }

        }

        ecsManager->killEntity(entity);

        spdlog::info("Hit max!");
    }
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
            handleSubject(novelTextComponent);
        }
    } else {
        subjectInd = 0;
    }
}

void NovelTextRenderSystem::handleSubject(NovelTextComponent& novelTextComponent) {
    novelTextComponent.readIndex -= novelTextComponent.subject.size();
    // spdlog::info("Saint Theresa!");
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




