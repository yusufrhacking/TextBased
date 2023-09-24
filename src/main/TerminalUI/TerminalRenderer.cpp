#include "TerminalRenderer.h"

Position TerminalRenderer::renderAuthor(const std::shared_ptr<Renderer> &renderer, Position startingPosition,
                                        const std::string& authorStr) {
    renderer->renderText(unusedCamera, startingPosition, TextComponent(authorStr), StyleComponent(Style::TERMINAL));
    return startingPosition + Position(authorStr.size() * TERMINAL_MONACO_TEXT_WIDTH_SCALER + 10, 0);
}

Position TerminalRenderer::renderPromptSymbol(const std::shared_ptr<Renderer> &renderer, Position startingPosition) {
    auto submittedPosition = startingPosition;
    renderer->renderText(unusedCamera, submittedPosition, TextComponent(">"), StyleComponent(Style::TERMINAL));
    return startingPosition + Position(TEXT_OFFSET, (float)0);
}

Position TerminalRenderer::renderLiveText(const std::shared_ptr<Renderer> &renderer, Position startingPosition,
                                          const std::string& currText) {
    auto terminalTextC = TextComponent(currText);
    renderer->renderText(unusedCamera, startingPosition, terminalTextC, StyleComponent(Style::TERMINAL));

    float textXLength = (float)currText.size() * TERMINAL_MONACO_TEXT_WIDTH_SCALER;
    return startingPosition + Position(textXLength, (float)0);
}

Position TerminalRenderer::renderUnderscore(const std::shared_ptr<Renderer> &renderer, Position startingPosition,
                                            const std::string& currText, bool isTerminalLive) {
    if (!isTerminalLive){
        return {};
    }

    auto submittedPosition = startingPosition + Position((float)0, UNDERSCORE_Y_OFFSET);

    if (showUnderscore > 30){
        renderer->renderText(unusedCamera, submittedPosition, TextComponent("_"), StyleComponent(Style::TERMINAL));
    }
    showUnderscore += 1;
    showUnderscore = showUnderscore % 60;
    return submittedPosition;
}