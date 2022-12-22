# include "events.h"

/* return values: 
-1.. if there is an error somewhere
0... to exit the program
1... to do nothing in main
*/
int handleEvent(
    SDL_Event event, 
    clickListener_t * clickListeners, 
    size_t clickListenersSize
) 
{
    switch(event.type) 
    {
        // handle window exit icon
        case SDL_QUIT:
            return 0;
        // handle keyboard events
        case SDL_KEYDOWN:
            switch(event.key.keysym.sym) 
            {
                // press escape to leave the program
                case SDLK_ESCAPE:
                    return 0;
            }
            break;
        // handle mouse events
        case SDL_MOUSEBUTTONDOWN:
            handleMouseEvent(event, clickListeners, clickListenersSize);
            break;
    }
    return 1;
}


// handle mouse events
void handleMouseEvent(
    SDL_Event event, 
    clickListener_t * clickListeners, 
    size_t clickListenersSize
)
{
    SDL_Point clickCoords = {event.button.x, event.button.y};
    switch(event.button.button) 
    {
        case SDL_BUTTON_LEFT:
            handleLeftClick(clickCoords, clickListeners, clickListenersSize);
            break;
    }
}


// handle left clicks
void handleLeftClick(
    SDL_Point clickCoords,
    clickListener_t * clickListeners,
    size_t clickListenersSize
)
{
    // check every click listener
    for(size_t i = 0; i < clickListenersSize; i++)
    {
        // if the click was on the click listener, execute the clicklistener's function
        if(SDL_PointInRect(&clickCoords, &(clickListeners[i].clickZone)))
        {
            clickListeners[i].callback(clickListeners[i].callbackArgs);
        }
    }
}
