#ifndef _TYPEDEFS_H_
#define _TYPEDEFS_H_

#include <SDL2/SDL.h>

// will contain all possible arguments for a callback function
typedef struct {
    SDL_Rect clickZone;
    void (*onClick)(const char categoryLetter, const unsigned short textureFileNumber);
    char tileLetter;
    unsigned short tileNumber;
} clickListener_t;

typedef struct {
    SDL_Window * window;
    SDL_Renderer * renderer;
} windowAndRenderer_t;

#endif
