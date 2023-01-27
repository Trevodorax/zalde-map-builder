#ifndef _TEXT_INPUT_BOX_H_
#define _TEXT_INPUT_BOX_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "typedefs.h"
#include "SDLUtils.h"
#include "constants.h"

int initTextInputBox(
    SDL_Renderer * renderer, 
    appContext_t * appContext
);

int displayTextInputBoxValue(
    SDL_Renderer * renderer,
    appContext_t * appContext
);

int renderInputBox(
    appContext_t * appContext,
    SDL_Renderer * renderer,
    SDL_Rect * rect
);

int eraseInputBox(
    SDL_Renderer * renderer
);

#endif
