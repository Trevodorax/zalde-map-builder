#include "button.h"

int createButton(
    SDL_Rect buttonRect,
    int (*callbackFunc)(),
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
        //! no function fail checks
        SDL_Color red = {255, 0, 0, 255};
        setDrawColor(renderer, red);
        SDL_RenderFillRect(renderer, &buttonRect);
    }
    

    SDL_RenderPresent(renderer);

    // create a clickListener with the values given in parameters
    clickListener_t newClickListener;
    newClickListener.clickZone = buttonRect;
    newClickListener.onClick = callbackFunc;

    // add the clickListener to the array of clickListeners
    printf("Size: %zu", *clickListenersSize);
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
