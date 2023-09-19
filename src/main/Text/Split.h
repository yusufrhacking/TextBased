#ifndef TEXTBASED_SPLIT_H
#define TEXTBASED_SPLIT_H

#include <string>
#include <sstream>
namespace Split{
    static std::vector<std::string> getWords(const std::string& processedText) {
        std::istringstream iss(processedText);
        std::string token;
        std::vector<std::string> words;

        while(std::getline(iss, token, ' ')) {
            words.push_back(token);
        }
        return words;
    }

}

#endif //TEXTBASED_SPLIT_H
