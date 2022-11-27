/*
SDL utils for every little action that might be needed
Must be very generic and not have anything specific to the game
*/

#define _SDLUTILS_H_

#include <SDL2/SDL.h>

#ifndef _TYPEDEFS_H_
#include "./typedefs.h"
#endif

int initWindowAndRenderer(
    WindowAndRenderer_t * createdWindow,
    const char * windowTitle,
    size_t windowSize
);

int setDrawColor(
    SDL_Renderer * renderer, 
    SDL_Color color
);

int setBackgroundColor(
    SDL_Renderer * renderer, 
    SDL_Color color
);

