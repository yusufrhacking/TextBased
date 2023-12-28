#ifndef TEXTBASED_NOVELTEXTRENDERSYSTEM_H
#define TEXTBASED_NOVELTEXTRENDERSYSTEM_H

#include "../ECSObjects/System.h"
#include "../Rendering/Renderer.h"
#include "NovelTextComponent.h"
#include "../Rendering/FixedRenderSystem.h"
#include "../PositionsAndMovement/PositionComponent.h"

class NovelTextRenderSystem: public DynamicRenderSystem {
private:
    std::string getLinedUpText(const std::string& text);
    std::chrono::steady_clock::time_point lastUpdateTime;
    int standardTypingDelayMilliseconds = 0;
    int currentWaitingTime = standardTypingDelayMilliseconds;
    int COMMA_MULTIPLIER = 7;
    size_t subjectCharInd = 0;
    size_t startWordIndOfSubject = 0;
    size_t startCharIndOfSubject = 0;
;

    void delayOnComma(char newChar);

    void ensureTextIsLined(TextComponent&textComponent);

    void skipReadingIfInstant(TextComponent&textComponent, NovelTextComponent&novelTextComponent);

    bool isTimePassed(std::chrono::milliseconds timeDiff);

    bool isRoomInText(TextComponent&textComponent, NovelTextComponent&novelTextComponent);

    void handleSubject(NovelTextComponent& novelTextComponent);

    void trackSubject(NovelTextComponent&novelTextComponent, char newChar);

    size_t findSubjectWordInd(std::vector<std::string> words, const std::string& subject);

    bool isAtEndOfReading(const NovelTextComponent& novelTextComponent, const TextComponent&textComponent);

    void readTheText(Entity entity, const std::shared_ptr<Renderer> &renderer, Camera camera);
    void convertTextToEntities(Entity entity, PositionComponent positionComponent, TextComponent& textComponent, NovelTextComponent& novelTextComponent);



public:
    NovelTextRenderSystem();
    void render(const std::shared_ptr<Renderer>& renderer, Camera camera) override;

};


#endif //TEXTBASED_NOVELTEXTRENDERSYSTEM_H
