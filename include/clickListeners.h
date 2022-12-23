#ifndef _CLICK_LISTENERS_H_
#define _CLICK_LISTENERS_H_

#include <SDL2/SDL.h>
#include "typedefs.h"

clickListener_t * initClickListeners();

int addClickListener(
    char type,
    clickListener_t * clickListeners,
    SDL_Rect clickZone,
    void (*callback)(void *),
    void * callbackArgs
);

void freeClickListeners(clickListener_t * clickListeners);

void freeClickListener(clickListener_t * clickListener);

int removeClickListenersByType(
    char type,
    clickListener_t * clickListeners
);

#endif