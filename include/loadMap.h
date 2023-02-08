#ifndef _LOAD_MAP_H_
#define _LOAD_MAP_H_

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include "map.h"
#include "typedefs.h"
#include "constants.h"

int loadMap(
    mapTile_t map[MAP_SIZE][MAP_SIZE], 
    char * mapName,
    SDL_Renderer * renderer
);

int handleLoadedTile(
    mapTile_t map[MAP_SIZE][MAP_SIZE],
    size_t x,
    size_t y,
    mapTile_t currentLoadedTile,
    SDL_Renderer * renderer
);

int isEmptyTexture(texture_t texture);

#endif
