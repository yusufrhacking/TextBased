#ifndef FONTGLOBALS_H
#define FONTGLOBALS_H

using RenderedVal = unsigned int;

static const int TEXT_C_FONT_SIZE = 15; //Must be a multiple of 5 in current config
static const int TERMINAL_FONT_SIZE = 15;

const RenderedVal MONACO_RENDERED_TEXT_WIDTH_SCALER = TEXT_C_FONT_SIZE * .6;
const RenderedVal TERMINAL_MONACO_TEXT_WIDTH_SCALER = TERMINAL_FONT_SIZE * .6;
const RenderedVal MONACO_HEIGHT_OF_A_LINE_OF_TEXT = TEXT_C_FONT_SIZE + 1;
const RenderedVal TERMINAL_MONACO_HEIGHT_LINE_OF_TEXT = TERMINAL_FONT_SIZE + 1;
const RenderedVal RENDERED_LINE_HEIGHT = 6;

#endif //FONTGLOBALS_H
