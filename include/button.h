#ifndef _BUTTON_H_
#define _BUTTON_H_

#include <SDL2/SDL.h>
#include "typedefs.h"
#include "SDLUtils.h"
#include "events.h"
#include "clickListeners.h"

int createButton(
    char type,
    SDL_Rect buttonRect,
    void (*callback)(void *),
    void * callbackArgs,
    SDL_Texture * backgroundTexture,
    clickListener_t * clickListeners,
    SDL_Renderer * renderer
);

int deleteButtonsByType(
    char type,
    SDL_Renderer * renderer,
    clickListener_t * clickListeners
);

int eraseButtonsByType(
    char type,
    SDL_Renderer * renderer,
    clickListener_t * clickListeners
);

#endif
