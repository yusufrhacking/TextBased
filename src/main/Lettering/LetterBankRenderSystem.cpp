#include "LetterBankRenderSystem.h"
#include "../HighLevel/ECSManager.h"
#include "CharacterDepositEvent.h"
#include "CharacterStorageSystem.h"
#include <string>

extern std::unique_ptr<ECSManager> ecsManager;

void LetterBankRenderSystem::render(const std::shared_ptr<Renderer> &renderer) {
    renderLetterBox(renderer);
    renderLetters(renderer);
}

void LetterBankRenderSystem::renderLetterBox(const std::shared_ptr<Renderer> &renderer) {
    renderer->renderFixedText(letterBoxPosition, TextComponent(letterBankText),
                              StyleComponent(Style::WHITE_MONACO_GENERIC));
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
                                      TextComponent(letterStr), StyleComponent(Style::UNUSED_LETTER_BANK));
            renderer->renderFixedText(tinyNumberPosition,
                                      TextComponent(std::to_string(tinyNumber)),
                                      StyleComponent(Style::UNUSED_TINY_NUMBER));
        } else{
            renderer->renderFixedText(submittedPosition,
                                      TextComponent(letterStr), StyleComponent(Style::USED_LETTER_BANK));
            renderer->renderFixedText(tinyNumberPosition,
                                      TextComponent(std::to_string(tinyNumber)),
                                      StyleComponent(Style::USED_TINY_NUMBER));
        }

        xCount++;
        if (xCount > rowReset){
            xCount = 1;
            yCount += 1;
        }
    }
}
