#ifndef TEXTBASED_ITEM_H
#define TEXTBASED_ITEM_H

#include <string>
#include <stdexcept>

enum class Item {
    AXE,
    WOOD,
    LETTER
};

static std::string ItemToString(const Item& item) {
    switch (item) {
        case Item::AXE:
            return "axe";
        case Item::WOOD:
            return "wood";
        default:
            throw std::invalid_argument("Invalid item value.");
    }
}

static Item StringToItem(const std::string& str) {
    if (str == "axe") {
        return Item::AXE;
    } else if (str == "wood") {
        return Item::WOOD;
    } else {
        throw std::invalid_argument("Invalid string value for Item.");
    }
}

#endif
