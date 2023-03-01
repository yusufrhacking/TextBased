#ifndef TEXTBASED_GLOBALS_H
#define TEXTBASED_GLOBALS_H
#include <bitset>

const unsigned int NUM_OF_COMPONENTS = 64;
using ComponentSignature = std::bitset<NUM_OF_COMPONENTS>;
const unsigned int MAX_ENTITIES = 1000;


static bool signaturesMatch(const ComponentSignature &entityComponentSignature, const ComponentSignature &systemComponentSignature) {
    return (entityComponentSignature & systemComponentSignature) == systemComponentSignature;
}


#endif //TEXTBASED_GLOBALS_H
