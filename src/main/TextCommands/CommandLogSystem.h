#ifndef TEXTBASED_COMMANDLOGSYSTEM_H
#define TEXTBASED_COMMANDLOGSYSTEM_H

#include "Command.h"
#include "../ECSObjects/System.h"
#include "../TextInput/ProspectiveTextCommandEvent.h"

class CommandLogSystem: public System {
    std::vector<Command> commands;
public:
    CommandLogSystem();

    void listenToEvents();

    void addCommand(const Command &command);

    std::vector<Command> getCommands() const;

    void onCommand(ProspectiveTextCommandEvent &event);
};


#endif //TEXTBASED_COMMANDLOGSYSTEM_H
