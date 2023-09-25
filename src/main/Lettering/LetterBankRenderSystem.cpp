#include "LetterBankRenderSystem.h"
#include "../HighLevel/ECSManager.h"
#include "CharacterDepositEvent.h"
#include "CharacterStorageSystem.h"

extern std::unique_ptr<ECSManager> ecsManager;

void LetterBankRenderSystem::render(const std::shared_ptr<Renderer> &renderer, Camera camera) {
    renderLetterBox(renderer);
    auto allLetters = Alphabet::allLetters();
    int xCount = 1;
    int yCount = 1;
    int rowReset = 7;
    for (auto letter: allLetters){
        auto submittedPosition = letterBoxPosition + Position(LETTER_X_OFFSET*xCount, LETTER_Y_OFFSET*yCount);
        std::string letterStr;
        letterStr.push_back(enum_to_char(letter));
        renderer->renderText(unusedCamera, submittedPosition,
                             TextComponent(letterStr), StyleComponent(Style::WHITE_MONACO_GENERIC));
        xCount++;
        if (xCount > rowReset){
            xCount = 1;
            yCount += 1;
        }
    }
    auto letterAllocations = ecsManager->getSystem<CharacterStorageSystem>().getAlphabet();
}

void LetterBankRenderSystem::renderLetterBox(const std::shared_ptr<Renderer> &renderer) {
    renderer->renderText(unusedCamera, letterBoxPosition, TextComponent(letterBankText), StyleComponent(Style::WHITE_MONACO_GENERIC));
}
