#ifndef _BUTTON_H_
#define _BUTTON_H_

#include <SDL2/SDL.h>
#include "typedefs.h"
#include "SDLUtils.h"

int createButton(
    SDL_Rect buttonRect, 
    int (*testFunc)(), 
    SDL_Color buttonColor, 
    clickListener_t ** clickListeners, 
    size_t * clickListenersSize,
    SDL_Renderer * renderer
);

#endif