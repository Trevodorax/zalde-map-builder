#ifndef _TYPEDEFS_H_
#define _TYPEDEFS_H_

#include <SDL2/SDL.h>

// will contain all possible arguments for a callback function
typedef struct clickListener_t clickListener_t;
struct clickListener_t{
    SDL_Rect clickZone;
    void (*callback)(void *);
    void * callbackArgs;
    clickListener_t * next;
};

typedef struct {
    char tileLetter;
    unsigned short tileNumber;
} setCurrentTileArgs_t;

typedef struct {
    char direction;
} setTexturePickerCategoryArgs_t;

typedef struct {
    SDL_Window * window;
    SDL_Renderer * renderer;
} windowAndRenderer_t;

#endif
