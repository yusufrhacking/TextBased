#include "TerminalRenderer.h"

Position TerminalRenderer::renderAuthor(const std::shared_ptr<Renderer> &renderer, Position startingPosition,
                                        const std::string& authorStr, Style style) {
    renderer->renderFixedText(startingPosition, TextComponent(authorStr), StyleComponent(style));
    return startingPosition + Position(authorStr.size() * TERMINAL_MONACO_TEXT_WIDTH_SCALER + 10, 0);
}

Position TerminalRenderer::renderPromptSymbol(const std::shared_ptr<Renderer> &renderer, Position startingPosition, Style style) {
    auto submittedPosition = startingPosition;
    renderer->renderFixedText(submittedPosition, TextComponent(">"), StyleComponent(style));
    return startingPosition + Position(TEXT_OFFSET, (float)0);
}

Position TerminalRenderer::renderText(const std::shared_ptr<Renderer> &renderer, Position startingPosition,
                                      const std::string& currText, Style style) {
    auto terminalTextC = TextComponent(currText);
    renderer->renderFixedText(startingPosition, terminalTextC, StyleComponent(style));

    float textXLength = (float)currText.size() * TERMINAL_MONACO_TEXT_WIDTH_SCALER;
    return startingPosition + Position(textXLength, (float)0);
}


Position TerminalRenderer::renderUnderscore(const std::shared_ptr<Renderer> &renderer, Position startingPosition,
                                            const std::string& currText, bool isTerminalLive, Style style) {
    if (!isTerminalLive){
        return {};
    }

    auto submittedPosition = startingPosition + Position((float)0, UNDERSCORE_Y_OFFSET);

    if (showUnderscore > 30){
        renderer->renderFixedText(submittedPosition, TextComponent("_"), StyleComponent(style));
    }
    showUnderscore += 1;
    showUnderscore = showUnderscore % 60;
    return submittedPosition;
}

