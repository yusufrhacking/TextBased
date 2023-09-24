#ifndef TEXTBASED_COMMAND_H
#define TEXTBASED_COMMAND_H

#include <string>
struct Command{
    std::string commandStr;
    std::string subjectStr;
    Command(std::string command, std::string subject): commandStr(command), subjectStr(subject){}

    std::string getFullCommandText(){
        if (!subjectStr.empty()){
            return commandStr + " " +  subjectStr;
        } else{
            return commandStr;
        }
    }
};

#endif //TEXTBASED_COMMAND_H
