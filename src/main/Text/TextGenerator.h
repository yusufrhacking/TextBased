#ifndef TEXTBASED_TEXTGENERATOR_H
#define TEXTBASED_TEXTGENERATOR_H

#include <string>

class TextGenerator {
public:
    static std::string getTreeText();
    static std::string getMountainText();
private:
    static std::string getXOffCenterOffset(int diff, std::string centerOffset);
};


#endif //TEXTBASED_TEXTGENERATOR_H
