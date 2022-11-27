#include "../include/SDLUtils.h"

int initWindowAndRenderer(
    WindowAndRenderer_t * createdWindow,
    const char * windowTitle,
    size_t windowSize
)
{
    createdWindow->window = SDL_CreateWindow(
        windowTitle, 
        SDL_WINDOWPOS_CENTERED, 
        SDL_WINDOWPOS_CENTERED, 
        windowSize, 
        windowSize, 
        SDL_WINDOW_SHOWN
    );
    if(     !createdWindow->window)
    {
        fprintf(stderr, "SDL_CreateWindow error : %s", SDL_GetError());
        return -1;
    }

    createdWindow->renderer = SDL_CreateRenderer(
        createdWindow->window,
        1,
        SDL_RENDERER_ACCELERATED
    );
    if(!createdWindow->renderer)
    {
        fprintf(stderr, "SDL_CreateRenderer error : %s", SDL_GetError());
        return -1;
    }

    return 0;
}

int setDrawColor(
    SDL_Renderer * renderer, 
    SDL_Color color
)
{
    if(SDL_SetRenderDrawColor(
        renderer, 
        color.r, 
        color.g, 
        color.b, 
        color.a
    ) != 0)
    {
        fprintf(stderr, "SDL_SetRenderDrawColor error : %s", SDL_GetError());
        return -1;
    }

    return 0;
};

int setBackgroundColor(
    SDL_Renderer * renderer, 
    SDL_Color color
)
{
    if(setDrawColor(renderer, color) != 0)
    {
        return -1;
    }
    
    if(SDL_RenderClear(renderer) != 0)
    {
        fprintf(stderr, "SDL_RenderClear error : %s", SDL_GetError());
        return -1;
    }

    return 0;
}