#ifndef TEXTBASED_TYPETOSTYLEMAPPER_H
#define TEXTBASED_TYPETOSTYLEMAPPER_H

#include "Style.h"

enum class Type{
    PLAIN_TEXT,
    PLAIN_TERMINAL_TEXT,
    OLD_TERMINAL_TEXT,
    ENGINEER_TERMINAL_TEXT,
    BRICOLEUR_TERMINAL_TEXT,
    PLAIN_LETTER,
    LETTER_BANK_SHELL,
    LETTER_BANK_EMPTY_LETTER,
    LETTER_BANK_USED_LETTER,
    TINY_NUMBER_EMPTY,
    TINY_NUMBER_USED,
    PLAYER_SIDE_TEXT
};

namespace Types {
    static Style typeToStyle(Type type) {
        switch(type) {
            case Type::PLAIN_TEXT: return Style::WHITE_MONACO_GENERIC;
            case Type::PLAIN_TERMINAL_TEXT: return Style::WHITE_TERMINAL;
            case Type::OLD_TERMINAL_TEXT: return Style::GRAY_TERMINAL;
            case Type::PLAIN_LETTER: return Style::GRAY_LETTER;
            case Type::ENGINEER_TERMINAL_TEXT: return Style::GREEN_TERMINAL;
            case Type::BRICOLEUR_TERMINAL_TEXT: return Style::AMBER_TERMINAL;
            case Type::LETTER_BANK_SHELL: return Style::WHITE_MONACO_GENERIC;
            case Type::LETTER_BANK_EMPTY_LETTER: return Style::WHITE_LETTER_IN_BANK;
            case Type::LETTER_BANK_USED_LETTER: return Style::GREEN_LETTER_IN_BANK;
            case Type::TINY_NUMBER_EMPTY: return Style::TINY_WHITE_NUMBER;
            case Type::TINY_NUMBER_USED: return Style::TINY_GREEN_NUMBER;
            case Type::PLAYER_SIDE_TEXT: return Style::TINY_GREEN_NUMBER;
            default: break;
        }
    }
}




#endif //TEXTBASED_TYPETOSTYLEMAPPER_H
