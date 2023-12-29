#ifndef TEXTBASED_SPLIT_H
#define TEXTBASED_SPLIT_H

#include <string>
#include <sstream>
#include "../Middlemarch/PunctuationMarks.h"
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
    static std::vector<std::string> getWordsAndPunctuation(const std::string& processedText) {
        std::vector<std::string> tokens;
        std::string token;

        for (char ch : processedText) {
            if (Punctuation::punctuationMarks.find(ch) != Punctuation::punctuationMarks.end() || ch == ' ') {
                if (!token.empty()) {
                    tokens.push_back(token);
                    token.clear();
                }
                if (ch != ' ') {
                    tokens.push_back(std::string(1, ch));
                }
            } else {
                token += ch;
            }
        }

        if (!token.empty()) {
            tokens.push_back(token);
        }

        return tokens;
    }

}

#endif //TEXTBASED_SPLIT_H
