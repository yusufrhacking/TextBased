#ifndef TEXTBASED_COMMANDLOGSYSTEM_H
#define TEXTBASED_COMMANDLOGSYSTEM_H

#include "AuthoredCommand.h"
#include "../ECSObjects/System.h"
#include "../TextInput/TextCommandEvent.h"

class CommandLogSystem: public System {
    std::vector<AuthoredCommand> commands;
public:
    CommandLogSystem();

    void listenToEvents();

    void addCommand(const AuthoredCommand &command);

    std::vector<AuthoredCommand> getAuthoredCommands() const;

    void onCommand(TextCommandEvent &event);
};


#endif //TEXTBASED_COMMANDLOGSYSTEM_H
