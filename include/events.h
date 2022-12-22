#ifndef _EVENTS_H_
#define _EVENTS_H_

#include <SDL2/SDL.h>

#include "typedefs.h"

clickListener_t * initClickListeners();

int addClickListener(
    clickListener_t * clickListeners, 
    SDL_Rect clickZone, 
    void (*callback)(void *),
    void * callbackArgs
);

void freeClickListeners(clickListener_t * clickListeners);

void freeClickListener(clickListener_t * clickListener);

int handleEvent(
    SDL_Event event, 
    clickListener_t * clickListeners
);

void handleMouseEvent(
    SDL_Event event, 
    clickListener_t * clickListeners
);

void handleLeftClick(
    SDL_Point clickCoords,
    clickListener_t * clickListeners
);

#endif
