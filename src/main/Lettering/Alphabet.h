#ifndef TEXTBASED_ALPHABET_H
#define TEXTBASED_ALPHABET_H
#include <vector>
#include <stdexcept>
#include "Letter.h"
#include <map>

struct Alphabet {
private:
    std::map<Letter, int> counts;

public:
    Alphabet() {}

    explicit Alphabet(int count) {
        for (int i = 0; i < ALPHABET_SIZE; ++i) {
            counts[static_cast<Letter>(i)] = count;
        }
    }

    void increment(Letter c) {
        counts[c]++;
    }

    void decrement(Letter c) {
        if (counts[c] <= 0) {
            throw std::runtime_error("0 letters left for that character");
        }
        counts[c]--;
    }

    [[nodiscard]] int getCount(Letter c) const {
        auto it = counts.find(c);
        if (it != counts.end()) {
            return it->second;
        }
        return 0; // Default value if not found
    }

    void reset() {
        for (auto &pair : counts) {
            pair.second = 0;
        }
    }
};



#endif //TEXTBASED_ALPHABET_H
