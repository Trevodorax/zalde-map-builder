#ifndef _TYPEDEFS_H_
#define _TYPEDEFS_H_

#include <SDL2/SDL.h>

// will contain all possible arguments for a callback function
typedef struct {
    SDL_Rect clickZone;
    void (*callback)(void *);
    char callbackType; // 'p': setCurrentTile
    void * callbackArgs;
} clickListener_t;

typedef struct {
    char tileLetter;
    unsigned short tileNumber;
} setCurrentTileArgs_t;

typedef struct {
    char navDirection;
} navDirectionsArgs_t;

typedef struct {
    SDL_Window * window;
    SDL_Renderer * renderer;
} windowAndRenderer_t;

#endif
