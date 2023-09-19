#ifndef TEXTBASED_ALPHABET_H
#define TEXTBASED_ALPHABET_H
#include <vector>
#include <stdexcept>
#include "Character.h"


struct Alphabet {
private:
    std::vector<int> counts;

public:
    Alphabet() : counts(ALPHABET_SIZE, 0) {}

    void increment(Character c) {
        counts[c]++;
    }

    void decrement(Character c) {
        if (counts[c] <= 0) {
            throw std::runtime_error("0 letters left for that character");
        }
        counts[c]--;
    }

    [[nodiscard]] int getCount(Character c) const {
        return counts[c];
    }

    void reset() {
        for (int &count : counts) {
            count = 0;
        }
    }
};



#endif //TEXTBASED_ALPHABET_H
