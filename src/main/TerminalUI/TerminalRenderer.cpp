#include "TerminalRenderer.h"

Position TerminalRenderer::renderAuthor(const std::shared_ptr<Renderer> &renderer, Position startingPosition,
                                        const std::string& authorStr, StyleComponent style) {
    auto finalStr = authorStr + " >";
    renderer->renderFixedText(startingPosition, TextComponent(finalStr), StyleComponent(style));
    return startingPosition + Position(finalStr.size() * TERMINAL_MONACO_TEXT_WIDTH_SCALER + 10, 0);
}

Position TerminalRenderer::renderPromptSymbol(const std::shared_ptr<Renderer> &renderer, Position startingPosition, StyleComponent style) {
    auto submittedPosition = startingPosition;
    renderer->renderFixedText(submittedPosition, TextComponent(">"), StyleComponent(style));
    return startingPosition + Position(TEXT_OFFSET, (float)0);
}

Position TerminalRenderer::renderText(const std::shared_ptr<Renderer> &renderer, Position startingPosition,
                                      const std::string& currText, StyleComponent style) {
    auto terminalTextC = TextComponent(currText);
    renderer->renderFixedText(startingPosition, terminalTextC, StyleComponent(style));

    float textXLength = (float)currText.size() * TERMINAL_MONACO_TEXT_WIDTH_SCALER;
    return startingPosition + Position(textXLength, (float)0);
}


Position TerminalRenderer::renderUnderscore(const std::shared_ptr<Renderer> &renderer, Position startingPosition,
                                            const std::string& currText, bool isTerminalLive, StyleComponent style) {
    if (!isTerminalLive){
        return {};
    }

    auto currentTime = std::chrono::steady_clock::now();
    auto timeDiff = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - lastUnderscoreToggleTime);

    if (timeDiff.count() >= underscoreToggleDelayMilliseconds) {
        underscoreVisible = !underscoreVisible;
        lastUnderscoreToggleTime = currentTime;
    }

    auto submittedPosition = startingPosition + Position((float)0, UNDERSCORE_Y_OFFSET);

    if (underscoreVisible) {
        renderer->renderFixedText(submittedPosition, TextComponent("_"), StyleComponent(style));
    }

    return submittedPosition;
}

