#ifndef TEXTBASED_LETTER_H
#define TEXTBASED_LETTER_H
#include <random>

enum class Letter {
    A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z,
    ALPHABET_SIZE
};

inline char enum_to_char(Letter character_enum) {
    if(character_enum < Letter::ALPHABET_SIZE) {
        return 'a' + static_cast<int>(character_enum);
    } else {
        return '\0';
    }
}

inline Letter char_to_enum(char character) {
    if(character >= 'a' && character <= 'z') {
        character = character - 'a' + 'A';
    }

    if(character >= 'A' && character <= 'Z') {
        return static_cast<Letter>(character - 'A');
    } else {
        return Letter::ALPHABET_SIZE;
    }
}

inline Letter get_random_letter() {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(0, static_cast<int>(Letter::ALPHABET_SIZE) - 1);

    return static_cast<Letter>(dist(mt));
}

#endif
