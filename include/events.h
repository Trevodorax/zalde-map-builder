#ifndef _EVENTS_H_
#define _EVENTS_H_

#include <SDL2/SDL.h>

#include "typedefs.h"

int handleEvent(
    SDL_Event event, 
    clickListener_t * clickListeners, 
    size_t clickListenersSize
);

void handleMouseEvent(
    SDL_Event event, 
    clickListener_t * clickListeners, 
    size_t clickListenersSize
);

void handleLeftClick(
    SDL_Point clickCoords,
    clickListener_t * clickListeners,
    size_t clickListenersSize
);

#endif
