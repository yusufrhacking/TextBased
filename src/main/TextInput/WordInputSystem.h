#ifndef TEXTBASED_WORDINPUTSYSTEM_H
#define TEXTBASED_WORDINPUTSYSTEM_H
#include "../HighLevel/ECSManager.h"
#include "TextCommandEvent.h"
#include "GameKeyEvent.h"
#include "TextInputEvent.h"
#include "../ECSObjects/System.h"

class WordInputSystem: public EntityRenderSystem {
public:
    WordInputSystem();
    void render(const std::shared_ptr<Renderer> &renderer, Camera camera) override;
private:
    std::string text;
    std::string lastCommand;
    bool listening_to_letters;
    void listenToEvents();
    void onGameKey(GameKeyEvent& event);
    void onText(TextInputEvent& event);

    void handleTextFlip();

    void handleBackSpace();

    void handleRepeatCommand();
};


#endif //TEXTBASED_WORDINPUTSYSTEM_H
