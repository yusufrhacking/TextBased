#ifndef TEXTBASED_ITEM_H
#define TEXTBASED_ITEM_H

#include <string>
#include <stdexcept>

enum Item {
    AXE,
    WOOD
};

static std::string ItemToString(const Item& item) {
    switch (item) {
        case AXE:
            return "axe";
        case WOOD:
            return "wood";
        default:
            throw std::invalid_argument("Invalid item value.");
    }
}

static Item StringToItem(const std::string& str) {
    if (str == "axe") {
        return AXE;
    } else if (str == "wood") {
        return WOOD;
    } else {
        throw std::invalid_argument("Invalid string value for Item.");
    }
}

#endif
