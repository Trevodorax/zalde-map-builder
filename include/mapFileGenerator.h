#ifndef _MAP_FILE_GENERATOR_H_
#define _MAP_FILE_GENERATOR_H_

#include "typedefs.h"
#include "constants.h"
#include "SDLUtils.h"
#include "button.h"

int createMapSaver(
    clickListener_t * clickListeners,
    SDL_Renderer * renderer,
    appContext_t * appContext
);

void saveMap(void * voidArgs);

int generateMapFile(mapTile_t map[MAP_SIZE][MAP_SIZE]);

void addTileToFile(mapTile_t tile, FILE * mapFile);

char getTileChar(mapTile_t tile);

#endif
