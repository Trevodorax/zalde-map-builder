# include "events.h"

/* return values: 
-1.. if there is an error somewhere
0... to exit the program
1... to do nothing in main
*/
int handleEvent(
    SDL_Event event, 
    clickListener_t * clickListeners,
    appContext_t * appContext,
    SDL_Renderer * renderer
)
{
    switch(event.type)
    {
        // handle window exit icon
        case SDL_QUIT:
            return 0;
        // handle keyboard events
        case SDL_KEYDOWN:
            if(event.key.keysym.sym == SDLK_ESCAPE)
            {
                return 0;
            }

            // handle the text input
            if(handleKeydown(
                event,
                appContext,
                renderer
            )!= 0)
            {
                return -1;
            }
            break;
        // handle mouse events
        case SDL_MOUSEBUTTONDOWN:
            handleMouseEvent(event, clickListeners);
            break;
    }
    return 1;
}


// handle mouse events
void handleMouseEvent(
    SDL_Event event, 
    clickListener_t * clickListeners
)
{
    SDL_Point clickCoords = {event.button.x, event.button.y};
    switch(event.button.button) 
    {
        case SDL_BUTTON_LEFT:
            handleLeftClick(clickCoords, clickListeners);
            break;
    }
}


// handle left clicks
void handleLeftClick(
    SDL_Point clickCoords,
    clickListener_t * clickListeners
)
{
    // check every click listener in the linked list
    clickListener_t * currentClickListener = clickListeners->next;
    while(currentClickListener != NULL)
    {
        // if the click was on the click listener, execute the clicklistener's function
        if(SDL_PointInRect(&clickCoords, &(currentClickListener->clickZone)))
        {
            currentClickListener->callback(currentClickListener->callbackArgs);
        }
        currentClickListener = currentClickListener->next;
    }

}
