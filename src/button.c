#include "button.h"

// generic button
int createButton(
    SDL_Rect buttonRect,
    void (*callback)(void *),
    void * callbackArgs,
    SDL_Texture * backgroundTexture,
    clickListener_t ** clickListeners,
    size_t * clickListenersSize,
    SDL_Renderer * renderer
)
{
    // render the button on the window
    if(backgroundTexture != NULL)
    {
        if(SDL_RenderCopy(renderer, backgroundTexture, NULL, &buttonRect) != 0) {
            fprintf(stderr, "SDL_RenderCopy error : %s", SDL_GetError());
            return -1;
        }
    } else {
        SDL_Color buttonColor = {0, 0, 255, 255};
        if(setDrawColor(renderer, buttonColor) != 0)
        {
            return -1;
        }
        
        if(SDL_RenderFillRect(renderer, &buttonRect) != 0)
        {
            fprintf(stderr, "SDL_RenderFillRect error : %s", SDL_GetError());
            return -1;
        }
    }

    // create a clickListener with the values given in parameters
    clickListener_t newClickListener;
    newClickListener.clickZone = buttonRect;
    newClickListener.callback = callback;
    newClickListener.callbackArgs = callbackArgs;


    // add the clickListener to the array of clickListeners
    *clickListeners = realloc(*clickListeners, ((*clickListenersSize) + 1) * sizeof(clickListener_t));
    if(*clickListeners == NULL)
    {
        fprintf(stderr, "realloc error");
        return -1;
    }

    *((*clickListeners) + (*clickListenersSize)) = newClickListener;

    (*clickListenersSize)++;

    return 0;
}
