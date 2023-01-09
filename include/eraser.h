#ifndef _ERASER_H_
#define _ERASER_H_

#include "typedefs.h"
#include "constants.h"
#include "button.h"

int createEraserButton(
    appContext_t * appContext, 
    SDL_Renderer * renderer, 
    clickListener_t * clickListeners
);

void startErasing(void * voidArgs);

#endif
