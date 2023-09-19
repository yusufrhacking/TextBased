#ifndef TEXTBASED_CHARACTER_H
#define TEXTBASED_CHARACTER_H

enum Character {
    A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z,
    ALPHABET_SIZE
};

inline char enum_to_char(Character character_enum) {
    if(character_enum < ALPHABET_SIZE) {
        return 'A' + static_cast<int>(character_enum);
    } else {
        return '\0';
    }
}

inline Character char_to_enum(char character) {
    if(character >= 'a' && character <= 'z') {
        character = character - 'a' + 'A';
    }

    if(character >= 'A' && character <= 'Z') {
        return static_cast<Character>(character - 'A');
    } else {
        return ALPHABET_SIZE;
    }
}

#endif
