#ifndef _TEXURE_PICKER_H_
#define _TEXURE_PICKER_H_

#include <SDL2/SDL.h>
#include "typedefs.h"
#include "utils.h"
#include "SDLUtils.h"
#include "button.h"
#include "texturePickerNavigation.h"
#include "currentTextureInfo.h"

int createTexturePickerCategory(
    SDL_Renderer * renderer, 
    appContext_t * appContext,
    clickListener_t * clickListeners,
    size_t texturePickerSize,
    SDL_Point texturePickerPosition
);

int createTile(
    SDL_Renderer * renderer,
    appContext_t * appContext,
    unsigned short textureFileNumber,
    clickListener_t * clickListeners,
    size_t tileSize,
    SDL_Point texturePickerPosition,
    int xTileIndex,
    int yTileIndex
);

void setCurrentTile(
    void * tileInfos
);

#endif
