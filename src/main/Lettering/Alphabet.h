#ifndef TEXTBASED_ALPHABET_H
#define TEXTBASED_ALPHABET_H
#include <vector>
#include <stdexcept>
#include "Letter.h"


struct Alphabet {
private:
    std::unordered_map<Letter, int> counts;

public:
    Alphabet() = default;

    explicit Alphabet(int count){
        for (const auto& letter : allLetters()) {
            counts[letter] = count;
        }
    }

    static std::vector<Letter> allLetters() {
        return {
                Letter::A, Letter::B, Letter::C, Letter::D, Letter::E,
                Letter::F, Letter::G, Letter::H, Letter::I, Letter::J,
                Letter::K, Letter::L, Letter::M, Letter::N, Letter::O,
                Letter::P, Letter::Q, Letter::R, Letter::S, Letter::T,
                Letter::U, Letter::V, Letter::W, Letter::X, Letter::Y,
                Letter::Z
        };
    }


    void increment(Letter c) {
        counts[c]++;
    }

    void decrement(Letter c) {
        if (counts[c] <= 0) {
            throw std::runtime_error("0 letters left for that letter");
        }
        counts[c]--;
    }

    [[nodiscard]] int getCount(Letter c) const {
        auto it = counts.find(c);
        if (it != counts.end()) {
            return it->second;
        }
        return 0;
    }

    void reset() {
        for (auto &pair : counts) {
            pair.second = 0;
        }
    }

};



#endif //TEXTBASED_ALPHABET_H
