#ifndef _TEXURE_PICKER_H_
#define _TEXURE_PICKER_H_

#include <SDL2/SDL.h>
#include "typedefs.h"
#include "utils.h"
#include "SDLUtils.h"
#include "button.h"

int createTexturePickerCategory(
    SDL_Renderer * renderer, 
    const char categoryLetter,
    clickListener_t ** clickListeners,
    size_t * clickListenersSize,
    size_t texturePickerSize,
    SDL_Point texturePickerPosition
);

int createTile(
    SDL_Renderer * renderer,
    char categoryLetter,
    unsigned short textureFileNumber,
    clickListener_t ** clickListeners,
    size_t * clickListenersSize,
    size_t tileSize,
    SDL_Point texturePickerPosition,
    int xTileIndex,
    int yTileIndex
);

int createNavigation(
    SDL_Renderer * renderer,
    clickListener_t ** clickListeners,
    size_t * clickListenersSize,
    SDL_Point navigationPosition
);

int createNavigationButton(
    SDL_Renderer * renderer,
    SDL_Rect buttonRect,
    SDL_Texture * buttonTexture,
    clickListener_t ** clickListeners,
    size_t * clickListenersSize,
    char navDirection
);

void setCurrentTile(
    void * tileInfos
);

void setTexturePickerCategory(
    void * args
);

#endif