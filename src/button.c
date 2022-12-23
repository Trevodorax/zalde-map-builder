#include "button.h"

// generic button
int createButton(
    char type,
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
        type,
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

int deleteButtonsByType(
    char type,
    SDL_Renderer * renderer,
    clickListener_t * clickListeners
)
{
    // erase the buttons from the window
    if(eraseButtonsByType(
        type,
        renderer,
        clickListeners
    ) != 0)
    {
        return -1;
    }

    // remove the buttons from the click listeners
    if(removeClickListenersByType(
        type,
        clickListeners
    ) != 0)
    {
        return -1;
    }

    return 0;
}

// erase all buttons from the window by type
int eraseButtonsByType(
    char type,
    SDL_Renderer * renderer,
    clickListener_t * clickListeners
)
{
    clickListener_t * currentClickListener = clickListeners->next;
    while(currentClickListener != NULL)
    {
        if(currentClickListener->type == type)
        {
            if(drawFillRect(
                currentClickListener->clickZone,
                (SDL_Color) {255, 255, 255, 255},
                renderer
            ) != 0) return -1;
        }
        currentClickListener = currentClickListener->next;
    }
    return 0;
}
