#ifndef _EVENTS_H_
#define _EVENTS_H_

#include <SDL2/SDL.h>

#include "typedefs.h"
#include "utils.h"
#include "textInput.h"

int handleEvent(
    SDL_Event event, 
    clickListener_t * clickListeners,
    appContext_t * appContext,
    SDL_Renderer * renderer
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
