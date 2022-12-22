#include "button.h"

// generic button
int createButton(
    SDL_Rect buttonRect,
    void (*callback)(void *),
    void * callbackArgs,
    SDL_Texture * backgroundTexture,
    clickListener_t * clickListeners,
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

    // add the button to the click listeners
    if(addClickListener(
        clickListeners,
        buttonRect,
        callback,
        callbackArgs
    ) != 0)
    {
        return -1;
    }

    return 0;
}
