#ifndef _TYPEDEFS_H_
#define _TYPEDEFS_H_

#include <SDL2/SDL.h>

typedef struct {
    SDL_Window * window;
    SDL_Renderer * renderer;
} WindowAndRenderer_t;

typedef struct {
    SDL_Rect clickZone;
    int (*onClick)();
} clickListener_t;

#endif
