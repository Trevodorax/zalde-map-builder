#ifndef _BUTTON_H_
#define _BUTTON_H_

#include <SDL2/SDL.h>
#include "typedefs.h"
#include "SDLUtils.h"

int createTilePickButton(
    SDL_Rect buttonRect,
    void (*callbackFunc)(const char, const unsigned short),
    char tileLetter,
    unsigned short tileNumber,
    SDL_Texture * backgroundTexture,
    clickListener_t ** clickListeners,
    size_t * clickListenersSize,
    SDL_Renderer * renderer
);

#endif