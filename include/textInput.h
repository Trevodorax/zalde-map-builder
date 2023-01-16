#ifndef _TEXT_INPUT_H_
#define _TEXT_INPUT_H_


#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "utils.h"
#include "typedefs.h"

int handleKeydown(
    SDL_Event event,
    sizedString_t * text,
    char inputContext
);

int writeLetter(
    char letter,
    sizedString_t * text
);

int deleteLetter(
    sizedString_t * text
);

int enterValue(
    sizedString_t * text,
    char inputContext
);
#endif