#include "NovelTextRenderSystem.h"

#include "SubjectComponent.h"
#include "../PositionsAndMovement/PositionComponent.h"
#include "../HighLevel/ECSManager.h"
#include "../PositionsAndMovement/CollisionComponent.h"
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
    for (auto entity : getRelevantEntities()) {
        readTheText(entity, renderer, camera);
    }
}

void NovelTextRenderSystem::readTheText(Entity entity, const std::shared_ptr<Renderer> &renderer, Camera camera) {
    auto& positionComponent = ecsManager->getComponentFromEntity<PositionComponent>(entity);
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
        bool isSubjectFound = trackSubject(novelTextComponent, newChar);
        if (isSubjectFound) {
            //Break up the text component

            // Calculate end of jit
            size_t finalNewIndex = startCharIndOfSubjectFIRST + novelTextComponent.subject.size();
            std::string textToBecomeEntities = textComponent.text.substr(0, finalNewIndex);
            TextComponent newTextComponent{textToBecomeEntities};

            // Turn this section into entities
            createEntitiesFromText(entity, positionComponent, newTextComponent, novelTextComponent);

            // Move text down the line + shift position as needed
            // Add dummy spacing from the left that corresponds to what the line has already shown
            size_t lines = 0;
            size_t spacesNeededForCurrLine = 0;
            for (size_t i = 0; i < textComponent.text.size(); i++) {
                if (i == startCharIndOfSubjectFIRST) {//Done with the searching b/c we found the subject
                    spacesNeededForCurrLine += novelTextComponent.subject.size();
                    break;
                }

                if (textComponent.text[i] == '\n') {
                    lines++;
                    spacesNeededForCurrLine = 0;
                }
                spacesNeededForCurrLine++;
            }

            std::string newText(spacesNeededForCurrLine, ' ');
            newText += textComponent.text.substr(finalNewIndex);

            textComponent.text = newText;
            novelTextComponent.readIndex = 0;

            // Move the position down the corresponding lines!
            positionComponent.shiftPosition(0, lines * MONACO_HEIGHT_OF_A_LINE_OF_TEXT);
        }
    }

    delayOnComma(newChar);

    std::string textToRender = textComponent.text.substr(0, novelTextComponent.readIndex);
    renderer->renderDynamicText(camera, positionComponent.getPosition(), TextComponent(textToRender), GenericStyleComponent());

    if (isAtEndOfReading(novelTextComponent, textComponent)) {
        createEntitiesFromText(entity, positionComponent, textComponent, novelTextComponent);
        ecsManager->killEntity(entity);
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

bool NovelTextRenderSystem::trackSubject(NovelTextComponent&novelTextComponent, char newChar) {
    if (newChar == novelTextComponent.subject[subjectCharInd]) {
        if (subjectCharInd == 0) {
            startCharIndOfSubjectFIRST = novelTextComponent.readIndex-1;
        }
        subjectCharInd++;
        if (subjectCharInd == novelTextComponent.subject.size()-1) {
            return true;
        }
    } else {
        subjectCharInd = 0;
    }
    return false;
}

void NovelTextRenderSystem::delayOnComma(char newChar) {
    if (newChar == ',') {
        currentWaitingTime = standardTypingDelayMilliseconds * COMMA_MULTIPLIER;
    } else {
        currentWaitingTime = standardTypingDelayMilliseconds;
    }
}

void NovelTextRenderSystem::createEntitiesFromText(Entity entity, PositionComponent positionComponent, TextComponent& textComponent, NovelTextComponent& novelTextComponent) {

    std::string subject = novelTextComponent.subject;
    auto words = Split::getWordsAndPunctuation(textComponent.text);
    size_t subjectWordInd = findSubjectWordInd(words, subject);
    Position currPosition = positionComponent.getPosition();

    size_t leadingWhitespaceCount = 0;
    for (char c : textComponent.text) {
        if (std::isspace(static_cast<unsigned char>(c))) {
            leadingWhitespaceCount++;
        } else {
            break;
        }
    }
    currPosition.xPos += leadingWhitespaceCount * MONACO_RENDERED_TEXT_WIDTH_SCALER;


    for (size_t i = 0; i < words.size(); i++) {
        std::string word = words[i];

        if (word.find('\n') != std::string::npos) {
            currPosition.xPos = positionComponent.getPosition().xPos;
            currPosition.yPos += MONACO_HEIGHT_OF_A_LINE_OF_TEXT;
            word.erase(std::remove_if(word.begin(), word.end(), [](char c) {
                return c == '\n';}), word.end());
        }

        Entity wordEntity = ecsManager->createEntity();
        ecsManager->addComponentToEntity<PositionComponent>(wordEntity, currPosition);
        ecsManager->addComponentToEntity<TextComponent>(wordEntity, word);
        ecsManager->addComponentToEntity<GenericStyleComponent>(wordEntity);
        ecsManager->addComponentToEntity<LiveComponent>(wordEntity);

        if(i == subjectWordInd) {
            ecsManager->getComponentFromEntity<TextComponent>(wordEntity).text = subject;
            ecsManager->addComponentToEntity<MainPlayerComponent>(wordEntity, std::make_shared<Velocity>(MONACO_RENDERED_TEXT_WIDTH_SCALER, MONACO_HEIGHT_OF_A_LINE_OF_TEXT));
            ecsManager->addComponentToEntity<SubjectComponent>(wordEntity);
            ecsManager->removeComponentFromEntity<GenericStyleComponent>(wordEntity);
            i += Split::getWordsAndPunctuation(subject).size();
            word = subject;
        }

        if (i < words.size()-2) {
            if (Split::punctuationMarks.contains(words[i+1][0])) {//If the next word is a punctuation mark
                currPosition += Position(word.size() * MONACO_RENDERED_TEXT_WIDTH_SCALER, 0);
            } else {
                currPosition += Position(word.size() * MONACO_RENDERED_TEXT_WIDTH_SCALER + MONACO_RENDERED_TEXT_WIDTH_SCALER, 0);
            }
        }

    }
    spdlog::info("Hit max!");

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

size_t NovelTextRenderSystem::findSubjectWordInd(std::vector<std::string> words, const std::string& subject) {
    std::vector<std::string> subjectWords = Split::getWords(subject);

    for (size_t i = 0; i < words.size(); ++i) {
        if (words[i] == subjectWords[0]) {
            bool match = true;
            for (size_t j = 1; j < subjectWords.size(); ++j) {
                if (i + j >= words.size() || words[i + j] != subjectWords[j]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                return i;
            }
        }
    }

    return std::string::npos;
}

bool NovelTextRenderSystem::isAtEndOfReading(const NovelTextComponent& novelTextComponent, const TextComponent&textComponent) {
    return novelTextComponent.readIndex >= textComponent.text.size()-1;
}


