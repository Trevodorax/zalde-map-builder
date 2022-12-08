#include "SDLUtils.h"

int initWindowAndRenderer(
    windowAndRenderer_t * createdWindow,
    const char * windowTitle,
    size_t windowSizeX,
    size_t windowSizeY
)
{
    createdWindow->window = SDL_CreateWindow(
        windowTitle, 
        SDL_WINDOWPOS_CENTERED, 
        SDL_WINDOWPOS_CENTERED, 
        windowSizeX, 
        windowSizeY, 
        SDL_WINDOW_SHOWN
    );
    if(!createdWindow->window)
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

SDL_Texture * getImageTexture(SDL_Renderer * renderer, const char * imageFileName)
{
    // load the image to pass into the texture
    SDL_Surface * imgSurface = NULL;

    // final returned texture
    SDL_Texture * imgTexture = NULL;

    // get the image surface
    imgSurface = SDL_LoadBMP(imageFileName);
    if(NULL == imgSurface)
    {
        return NULL;
    }

    // transform the surface into a texture
    imgTexture = SDL_CreateTextureFromSurface(renderer, imgSurface);
    if(imgTexture == NULL)
    {
        fprintf(stderr, "Erreur SDL_CreateTextureFromSurface : %s", SDL_GetError());
        return NULL;
    }

    // free the surface (it was just to create the texture)
    SDL_FreeSurface(imgSurface);

    return imgTexture;
}
