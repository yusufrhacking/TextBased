#ifndef TEXTBASED_LETTERBANKRENDERSYSTEM_H
#define TEXTBASED_LETTERBANKRENDERSYSTEM_H
#include "../Rendering/DynamicRenderSystem.h"
#include "../Rendering/FixedRenderSystem.h"
#include "../UIShow/HideLetterBankEvent.h"
#include "../UIShow/ShowLetterBankEvent.h"


class LetterBankRenderSystem: public FixedRenderSystem {
private:
    std::string letterBankText = "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n"
                                 "$                                    $\n"
                                 "$                                    $\n"
                                 "$                                    $\n"
                                 "$                                    $\n"
                                 "$                                    $\n"
                                 "$                                    $\n"
                                 "$                                    $\n"
                                 "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$";
    Position letterBoxPosition = Window::getTopRightPosition() -
            Position(TextComponent::getTextWidthInChars(letterBankText) * MONACO_RENDERED_TEXT_WIDTH_SCALER, 0);
    float LETTER_X_OFFSET = 40;
    float LETTER_Y_OFFSET = 25;
    bool toRender = true;

    void onHide(HideLetterBankEvent& event);
    void onShow(ShowLetterBankEvent& event);

public:
    LetterBankRenderSystem();
    void render(const std::shared_ptr<Renderer>& renderer) override;

    void renderLetterBox(const std::shared_ptr<Renderer> &renderer);

    void renderLetters(const std::shared_ptr<Renderer> &renderer);
};


#endif //TEXTBASED_LETTERBANKRENDERSYSTEM_H
