#ifndef TEXTBASED_LETTERBANKRENDERSYSTEM_H
#define TEXTBASED_LETTERBANKRENDERSYSTEM_H
#include "../Rendering/RenderSystem.h"

class LetterBankRenderSystem: public RenderSystem {
private:
    Camera unusedCamera{Position(0, 0)};
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
            Position(TextComponent::getTextWidth(letterBankText)*MONACO_RENDERED_TEXT_WIDTH_SCALER, 0);
public:
    LetterBankRenderSystem() = default;
    void render(const std::shared_ptr<Renderer>& renderer, Camera camera) override;

    void renderLetterBox(const std::shared_ptr<Renderer> &renderer);
};


#endif //TEXTBASED_LETTERBANKRENDERSYSTEM_H
