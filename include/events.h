#ifndef _EVENTS_H_
#define _EVENTS_H_

#include <SDL2/SDL.h>

#include "typedefs.h"

int handleEvent(
    SDL_Event event, 
    clickListener_t * clickListeners, 
    size_t clickListenersSize
);

#endif
