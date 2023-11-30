#include "LetterBankRenderSystem.h"
#include "../HighLevel/ECSManager.h"
#include "CharacterDepositEvent.h"
#include "CharacterStorageSystem.h"
#include <string>

extern std::unique_ptr<ECSManager> ecsManager;

extern std::unique_ptr<EventBus> eventBus;

LetterBankRenderSystem::LetterBankRenderSystem() {
    eventBus->listenToEvent<HideLetterBankEvent>(this, &LetterBankRenderSystem::onHide);
}

void LetterBankRenderSystem::onHide(HideLetterBankEvent& event) {
    toRender = false;
}

void LetterBankRenderSystem::render(const std::shared_ptr<Renderer> &renderer) {
    if (!toRender) return;
    renderLetterBox(renderer);
    renderLetters(renderer);
}

void LetterBankRenderSystem::renderLetterBox(const std::shared_ptr<Renderer> &renderer) {
    renderer->renderFixedText(letterBoxPosition, TextComponent(letterBankText),
                              StyleComponent(Type::LETTER_BANK_SHELL));
}

void LetterBankRenderSystem::renderLetters(const std::shared_ptr<Renderer> &renderer) {
    auto allLetters = Alphabet::allLetters();
    auto letterAllocations = ecsManager->getSystem<CharacterStorageSystem>().getAlphabet();
    int xCount = 1;
    int yCount = 1;
    int rowReset = 7;
    for (auto letter: allLetters) {
        auto submittedPosition = letterBoxPosition + Position(LETTER_X_OFFSET * xCount, LETTER_Y_OFFSET * yCount);

        std::string letterStr;
        letterStr.push_back(enum_to_char(letter));
        int tinyNumber = letterAllocations.getCount(letter);
        auto tinyNumberPosition = submittedPosition + Position(8, 8);

        if (tinyNumber == 0){
            renderer->renderFixedText(submittedPosition,
                                      TextComponent(letterStr), StyleComponent(Type::LETTER_BANK_EMPTY_LETTER));
            renderer->renderFixedText(tinyNumberPosition,
                                      TextComponent(std::to_string(tinyNumber)),
                                      StyleComponent(Type::TINY_NUMBER_EMPTY));
        } else{
            renderer->renderFixedText(submittedPosition,
                                      TextComponent(letterStr), StyleComponent(Type::LETTER_BANK_USED_LETTER));
            renderer->renderFixedText(tinyNumberPosition,
                                      TextComponent(std::to_string(tinyNumber)),
                                      StyleComponent(Type::TINY_NUMBER_USED));
        }

        xCount++;
        if (xCount > rowReset){
            xCount = 1;
            yCount += 1;
        }
    }
}
