#ifndef TEXTBASED_NOVELTEXTRENDERSYSTEM_H
#define TEXTBASED_NOVELTEXTRENDERSYSTEM_H

#include "../ECSObjects/System.h"
#include "../Rendering/Renderer.h"
#include "NovelTextComponent.h"
#include "../Rendering/FixedRenderSystem.h"

class NovelTextRenderSystem: public FixedRenderSystem {
private:
    std::string getLinedUpText(const std::string& text);
    std::chrono::steady_clock::time_point lastUpdateTime;
    int standardTypingDelayMilliseconds = 40;
    int currentWaitingTime = standardTypingDelayMilliseconds;
    int COMMA_MULTIPLIER = 7;
    size_t subjectInd = 0;
    size_t startIndOfSubject = 0;



    void readTheText(Entity entity, const std::shared_ptr<Renderer> &renderer);


public:
    NovelTextRenderSystem();
    void render(const std::shared_ptr<Renderer>& renderer) override;

    void delayOnComma(char newChar);

    void ensureTextIsLined(TextComponent&textComponent);

    void skipReadingIfInstant(TextComponent&textComponent, NovelTextComponent&novelTextComponent);

    bool isTimePassed(std::chrono::milliseconds timeDiff);

    bool isRoomInText(TextComponent&textComponent, NovelTextComponent&novelTextComponent);

    void handleSubject(NovelTextComponent& novelTextComponent);

    void trackSubject(NovelTextComponent&novelTextComponent, char newChar);
};


#endif //TEXTBASED_NOVELTEXTRENDERSYSTEM_H
