#ifndef TEXTBASED_LETTERSTORAGESYSTEM_H
#define TEXTBASED_LETTERSTORAGESYSTEM_H


#include <string>
#include "Alphabet.h"

class LetterStorageSystem {
public:
    bool spendWord(std::string word);
    const Alphabet& getLetterCounts();
private:
};


#endif //TEXTBASED_LETTERSTORAGESYSTEM_H
