#ifndef _TEXT_INPUT_BOX_H_
#define _TEXT_INPUT_BOX_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "typedefs.h"
#include "SDLUtils.h"

#define LETTER_SIZE 10


int initTextInputBox(
    SDL_Renderer * renderer, 
    appContext_t * appContext,
    size_t inputBoxSizeX,
    size_t inputBoxSizeY,
    SDL_Point textInputBoxPosition
);

int displayTextInputBoxValue(
    SDL_Renderer * renderer,
    appContext_t * appContext,
    size_t inputBoxSizeX,
    size_t inputBoxSizeY,
    SDL_Point textInputBoxPosition
);

int addSurfaceToRenderer(
    appContext_t * appContext,
    SDL_Renderer * renderer,
    SDL_Rect * rect
);

#endif
