#ifndef TEXTBASED_COMMANDLOGSYSTEM_H
#define TEXTBASED_COMMANDLOGSYSTEM_H

#include "AuthoredCommand.h"
#include "../ECSObjects/System.h"
#include "../TextInput/TextCommandEvent.h"
#include "../Diegesis/EngineerTerminalEvent.h"
#include "../Grammar/GrammarEvent.h"

class CommandLogSystem: public System {
    std::vector<AuthoredCommand> commands;
public:
    CommandLogSystem();

    void listenToEvents();

    void addCommand(const AuthoredCommand &command);

    std::vector<AuthoredCommand> getAuthoredCommands() const;

    void onCommand(GrammarEvent &event);

    void onEngineerText(EngineerTerminalEvent &event);
};


#endif //TEXTBASED_COMMANDLOGSYSTEM_H
