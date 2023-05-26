#ifndef TEXTBASED_GLOBALS_H
#define TEXTBASED_GLOBALS_H
#include <bitset>
#include "Helpers/Objects/Position.h"
#include "Game/GameSystems/Window/Window.h"
extern std::unique_ptr<Window> window;

const unsigned int NUM_OF_COMPONENTS = 64;
using ComponentSignature = std::bitset<NUM_OF_COMPONENTS>;
const unsigned int MAX_ENTITIES = 1000;
const unsigned int MAP_WIDTH = 1000;
const unsigned int MAP_HEIGHT = 1000;
static int currFrame = 0;


using RenderedVal = unsigned int;

static const int FONT_SIZE = 15; //Must be a multiple of 5 in current config

const RenderedVal RENDERED_TEXT_WIDTH_SCALER = FONT_SIZE * .6;
const RenderedVal HEIGHT_OF_A_LINE_OF_TEXT = FONT_SIZE + 1;
const RenderedVal RENDERED_LINE_HEIGHT = 6;

enum Style{
    WHITE_MONACO_GENERIC
};



static bool signaturesMatch(const ComponentSignature &entityComponentSignature, const ComponentSignature &systemComponentSignature) {
    return (entityComponentSignature & systemComponentSignature) == systemComponentSignature;
}


#endif //TEXTBASED_GLOBALS_H
