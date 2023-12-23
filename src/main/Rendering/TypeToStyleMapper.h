#ifndef TEXTBASED_TYPETOSTYLEMAPPER_H
#define TEXTBASED_TYPETOSTYLEMAPPER_H

#include "RenderStyle.h"

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
    static RenderStyle typeToStyle(Type type) {
        switch(type) {
            case Type::PLAIN_TEXT: return RenderStyle::WHITE_MONACO_GENERIC;
            case Type::PLAIN_TERMINAL_TEXT: return RenderStyle::WHITE_TERMINAL;
            case Type::OLD_TERMINAL_TEXT: return RenderStyle::GRAY_TERMINAL;
            case Type::PLAIN_LETTER: return RenderStyle::GRAY_LETTER;
            case Type::ENGINEER_TERMINAL_TEXT: return RenderStyle::GREEN_TERMINAL;
            case Type::BRICOLEUR_TERMINAL_TEXT: return RenderStyle::AMBER_TERMINAL;
            case Type::LETTER_BANK_SHELL: return RenderStyle::WHITE_MONACO_GENERIC;
            case Type::LETTER_BANK_EMPTY_LETTER: return RenderStyle::WHITE_LETTER_IN_BANK;
            case Type::LETTER_BANK_USED_LETTER: return RenderStyle::GREEN_LETTER_IN_BANK;
            case Type::TINY_NUMBER_EMPTY: return RenderStyle::TINY_WHITE_NUMBER;
            case Type::TINY_NUMBER_USED: return RenderStyle::TINY_GREEN_NUMBER;
            case Type::PLAYER_SIDE_TEXT: return RenderStyle::TINY_GREEN_NUMBER;
            default: break;
        }
    }
}




#endif //TEXTBASED_TYPETOSTYLEMAPPER_H
