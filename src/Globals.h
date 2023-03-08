#ifndef TEXTBASED_GLOBALS_H
#define TEXTBASED_GLOBALS_H
#include <bitset>
#include "Objects/Position.h"
#include "Game/GameSystems/Window/Window.h"
extern std::unique_ptr<Window> window;

const unsigned int NUM_OF_COMPONENTS = 64;
using ComponentSignature = std::bitset<NUM_OF_COMPONENTS>;
const unsigned int MAX_ENTITIES = 1000;

using Size = unsigned int;

const Size RENDERED_TEXT_WIDTH_SCALER = 6;
const Size RENDERED_TEXT_HEIGHT = 11;


static bool signaturesMatch(const ComponentSignature &entityComponentSignature, const ComponentSignature &systemComponentSignature) {
    return (entityComponentSignature & systemComponentSignature) == systemComponentSignature;
}


#endif //TEXTBASED_GLOBALS_H
