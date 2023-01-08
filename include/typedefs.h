#ifndef _TYPEDEFS_H_
#define _TYPEDEFS_H_

#include <SDL2/SDL.h>
#include "constants.h"

// will contain all possible arguments for a callback function
typedef struct clickListener_t clickListener_t;
struct clickListener_t {
    char type;
    SDL_Rect clickZone;
    void (*callback)(void *);
    void * callbackArgs;
    clickListener_t * next;
};

typedef struct {
    char letter;
    unsigned short number;
} texture_t;

typedef struct {
    texture_t primaryTexture;
    texture_t secondaryTexture;
} mapTile_t;

typedef struct {
    char currentTileLetter;
    unsigned short currentTileNumber;
    char texturePickerLetter;
    mapTile_t map[MAP_SIZE][MAP_SIZE];
} appContext_t;

typedef struct {
    char tileLetter;
    unsigned short tileNumber;
    appContext_t * appContext;
} setCurrentTileArgs_t;

typedef struct {
    char direction;
    appContext_t * appContext;
    SDL_Renderer * renderer;
    clickListener_t * clickListeners;
} setTexturePickerCategoryArgs_t;

typedef struct {
    appContext_t * appContext;
    size_t x;
    size_t y;
    SDL_Renderer * renderer;
} setMapTileArgs_t;

typedef struct {
    appContext_t * appContext;
} startErasingArgs_t;

typedef struct {
    SDL_Window * window;
    SDL_Renderer * renderer;
} windowAndRenderer_t;

#endif
