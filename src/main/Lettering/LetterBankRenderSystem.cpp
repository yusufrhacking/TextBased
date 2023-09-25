#include "LetterBankRenderSystem.h"
#include "../HighLevel/ECSManager.h"
#include "CharacterDepositEvent.h"
#include "CharacterStorageSystem.h"
#include <string>

extern std::unique_ptr<ECSManager> ecsManager;

void LetterBankRenderSystem::render(const std::shared_ptr<Renderer> &renderer, Camera camera) {
    renderLetterBox(renderer);
    renderLetters(renderer);
}

void LetterBankRenderSystem::renderLetterBox(const std::shared_ptr<Renderer> &renderer) {
    renderer->renderText(unusedCamera, letterBoxPosition, TextComponent(letterBankText),
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

        renderer->renderText(unusedCamera, submittedPosition,
                             TextComponent(letterStr), StyleComponent(Style::WHITE_MONACO_GENERIC));
        int tinyNumber = letterAllocations.getCount(letter);
        auto tinyNumberPosition = submittedPosition + Position(8, 8);

        renderer->renderText(unusedCamera, tinyNumberPosition,
                             TextComponent(std::to_string(tinyNumber)), StyleComponent(Style::TINY_NUMBER));

        xCount++;
        if (xCount > rowReset){
            xCount = 1;
            yCount += 1;
        }
    }
}
