#ifndef TEXTBASED_COMMAND_H
#define TEXTBASED_COMMAND_H

#include <string>
#include <utility>
struct Command{
    std::string commandStr;
    std::string subjectStr;

    explicit Command(std::string text): commandStr(std::move(text)) {}
    Command(std::string command, std::string subject): commandStr(std::move(command)), subjectStr(std::move(subject)){}

    [[nodiscard]] std::string getFullCommandText() const{
        if (!subjectStr.empty()){
            return commandStr + " " +  subjectStr;
        } else{
            return commandStr;
        }
    }
};

#endif //TEXTBASED_COMMAND_H
