#include "SDLUtils.h"


// create a window and a renderer tied together
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
        fprintf(stderr, "\nSDL_CreateWindow error : %s", SDL_GetError());
        return -1;
    }

    createdWindow->renderer = SDL_CreateRenderer(
        createdWindow->window,
        1,
        SDL_RENDERER_ACCELERATED
    );
    if(!createdWindow->renderer)
    {
        fprintf(stderr, "\nSDL_CreateRenderer error : %s", SDL_GetError());
        return -1;
    }

    return 0;
}

void freeWindowAndRenderer(windowAndRenderer_t * windowAndRenderer)
{
    if(windowAndRenderer->window)
    {
        SDL_DestroyWindow(windowAndRenderer->window);
    }
    if(windowAndRenderer->renderer)
    {
        SDL_DestroyRenderer(windowAndRenderer->renderer);
    }
}


// set the draw color of the renderer
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
        fprintf(stderr, "\nSDL_SetRenderDrawColor error : %s", SDL_GetError());
        return -1;
    }

    return 0;
};


// set the background color of the renderer
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
        fprintf(stderr, "\nSDL_RenderClear error : %s", SDL_GetError());
        return -1;
    }

    return 0;
}


// get a texture from an image file name (bmp)
SDL_Texture * getImageTexture(SDL_Renderer * renderer, const char * imageFileName)
{
    // load the image to pass into the texture
    SDL_Surface * imgSurface = NULL;

    // final returned texture
    SDL_Texture * imgTexture = NULL;

    if(imageFileName == NULL)
    {
        return NULL;
    }

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
        fprintf(stderr, "\nError SDL_CreateTextureFromSurface : %s", SDL_GetError());
        return NULL;
    }

    // free the surface (it was just to create the texture)
    SDL_FreeSurface(imgSurface);

    return imgTexture;
}

// draw a fill rectangle of the given color
int drawFillRect(
    SDL_Rect rect,
    SDL_Color color,
    SDL_Renderer * renderer
)
{
    if(setDrawColor(renderer, color) != 0)
    {
        return -1;
    }

    if(SDL_RenderFillRect(renderer, &rect) != 0)
    {
        fprintf(stderr, "\nSDL_RenderFillRect error : %s", SDL_GetError());
        return -1;
    }

    return 0;
}

int drawThickRect(
    SDL_Rect rect,
    size_t thickness,
    SDL_Color color,
    SDL_Renderer * renderer
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
        fprintf(stderr, "\nSDL_SetRenderDrawColor error : %s", SDL_GetError());
        return -1;
    }

    SDL_Rect currentContainerRect;

    for(size_t i = 0; i < thickness; i++)
    {
        currentContainerRect.x = rect.x - i;
        currentContainerRect.y = rect.y - i;
        currentContainerRect.w = rect.w + 2 * i;
        currentContainerRect.h = rect.h + 2 * i;

        if(SDL_RenderDrawRect(
            renderer, 
            &currentContainerRect
        ) != 0)
        {
            fprintf(stderr, "\nSDL_RenderDrawRect error : %s", SDL_GetError());
            return -1;
        }
    }

    return 0;
}
