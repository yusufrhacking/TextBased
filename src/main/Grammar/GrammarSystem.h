#ifndef TEXTBASED_GRAMMARSYSTEM_H
#define TEXTBASED_GRAMMARSYSTEM_H
#include "GrammarEvent.h"
#include "../ECSObjects/System.h"
#include "../Text/Split.h"

class GrammarSystem {
private:
    std::set<std::string> commandKeywords;
    std::set<std::string> subjectKeywords;

public:
    void addCommandKeyword(const std::string& keyword) {
        commandKeywords.insert(keyword);
    }

    void removeCommandKeyword(const std::string& keyword) {
        commandKeywords.erase(keyword);
    }

    void addSubjectKeyword(const std::string& keyword) {
        subjectKeywords.insert(keyword);
    }

    void removeSubjectKeyword(const std::string& keyword) {
        subjectKeywords.erase(keyword);
    }

    [[nodiscard]] bool isCommandKeyword(const std::string& keyword) const {
        return commandKeywords.find(keyword) != commandKeywords.end();
    }

    [[nodiscard]] bool isSubjectKeyword(const std::string& keyword) const {
        return subjectKeywords.find(keyword) != subjectKeywords.end();
    }

    [[nodiscard]] std::pair<std::string, std::string> splitCommandAndSubject(const std::string& text) const {
        auto words = Split::getWords(text);  // Assuming you have a getWords function

        std::string command = "";
        std::string subject = "";

        if (!words.empty() && isCommandKeyword(words[0])) {
            command = words[0];
            subject = (words.size() > 1 && isSubjectKeyword(words[1])) ? words[1] : "";
        }

        return {command, subject};
    }
};


#endif //TEXTBASED_GRAMMARSYSTEM_H
