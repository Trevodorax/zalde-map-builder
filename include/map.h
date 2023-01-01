#ifndef _MAP_H_
#define _MAP_H_

#include "constants.h"
#include "typedefs.h"
#include "button.h"
#include "SDLUtils.h"
#include "utils.h"

void initMap(texture_t map[MAP_SIZE][MAP_SIZE]);

void printMap(texture_t map[MAP_SIZE][MAP_SIZE]);

int createMap(
    clickListener_t * clickListeners,
    SDL_Renderer * renderer,
    appContext_t * appContext
);

int createMapTile(
    size_t x,
    size_t y,
    clickListener_t * clickListeners, 
    SDL_Renderer * renderer,
    appContext_t * appContext
);

void setMapTile(void * callbackArgs);

SDL_Rect getMapTileRect(
    size_t x, 
    size_t y
);

int updateMapTileTexture(
    size_t x, 
    size_t y, 
    char letter, 
    unsigned short number, 
    SDL_Renderer * renderer
);

#endif
