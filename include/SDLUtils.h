/*
SDL utils for every little action that might be needed
Must be very generic and not have anything specific to the game
*/

#ifndef _SDLUTILS_H_
#define _SDLUTILS_H_

#include <SDL2/SDL.h>
#include "typedefs.h"

int initWindowAndRenderer(
    windowAndRenderer_t * createdWindow,
    const char * windowTitle,
    size_t windowSizeX,
    size_t windowSizeY
);

int setDrawColor(
    SDL_Renderer * renderer, 
    SDL_Color color
);

int setBackgroundColor(
    SDL_Renderer * renderer, 
    SDL_Color color
);

SDL_Texture * getImageTexture(
    SDL_Renderer * renderer,
    const char * imageFileName
);

#endif
