#ifndef TEXTBASED_PLAYERSIDETEXTSYSTEM_H
#define TEXTBASED_PLAYERSIDETEXTSYSTEM_H

#include "../ECSObjects/System.h"
#include "../Rendering/DynamicRenderSystem.h"
#include "../TextCommands/AuthoredCommand.h"
#include "../TextInput/TextCommandEvent.h"

class PlayerSideTextSystem: public DynamicRenderSystem {
    std::vector<AuthoredCommand> commands;

public:
    explicit PlayerSideTextSystem();

    void render(const std::shared_ptr<Renderer>& renderer, Camera camera) override;

    void listenToEvents();

    void onCommand(TextCommandEvent &event);

//    Position getPlayerPosition();

};



#endif //TEXTBASED_PLAYERSIDETEXTSYSTEM_H
