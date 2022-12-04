#include "button.h"

int createButton(
    SDL_Rect buttonRect,
    int (*testFunc)(),
    SDL_Color buttonColor,
    clickListener_t ** clickListeners,
    size_t * clickListenersSize,
    SDL_Renderer * renderer
)
{
    // render the button on the window
    if(setDrawColor(renderer, buttonColor) != 0)
    {
        fprintf(stderr, "setDrawColor error : %s", SDL_GetError());
        return -1;
    }

    if(SDL_RenderFillRect(renderer, &buttonRect) != 0)
    {
        fprintf(stderr, "SDL_RenderFillRect error : %s", SDL_GetError());
        return -1;
    }

    SDL_RenderPresent(renderer);

    // create a clickListener with the values given in parameters
    clickListener_t newClickListener;
    newClickListener.clickZone = buttonRect;
    newClickListener.onClick = testFunc;

    // add the clickListener to the array of clickListeners
    *clickListeners = realloc(*clickListeners, (*clickListenersSize) + 1);
    if(*clickListeners == NULL)
    {
        fprintf(stderr, "realloc error");
        return -1;
    }

    *((*clickListeners) + (*clickListenersSize)) = newClickListener;

    (*clickListenersSize)++;

    return 0;
}
