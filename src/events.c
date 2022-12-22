# include "events.h"

/* ----- click listener linked list ----- */
// init the click listeners
clickListener_t * initClickListeners()
{
    clickListener_t * clickListeners = malloc(sizeof(clickListener_t));
    if(clickListeners == NULL)
    {
        fprintf(stderr, "malloc error : %s", SDL_GetError());
        return NULL;
    }
    clickListeners->next = NULL;
    return clickListeners;
}

// add a click listener to the list
int addClickListener(
    clickListener_t * clickListeners,
    SDL_Rect clickZone,
    void (*callback)(void *),
    void * callbackArgs
)
{
    clickListener_t * newClickListener = malloc(sizeof(clickListener_t));
    if(newClickListener == NULL)
    {
        fprintf(stderr, "malloc error : %s", SDL_GetError());
        return -1;
    }
    newClickListener->clickZone = clickZone;
    newClickListener->callback = callback;
    newClickListener->callbackArgs = callbackArgs;

    newClickListener->next = NULL;

    clickListener_t * currentClickListener = clickListeners;
    while(currentClickListener->next != NULL)
    {
        currentClickListener = currentClickListener->next;
    }
    currentClickListener->next = newClickListener;
    return 0;
}

// free the click listeners
void freeClickListeners(clickListener_t * clickListeners)
{
    clickListener_t * currentClickListener = clickListeners->next;
    while(currentClickListener != NULL)
    {
        clickListener_t * nextClickListener = currentClickListener->next;
        freeClickListener(currentClickListener);

        currentClickListener = nextClickListener;
    }
    free(clickListeners);
}

void freeClickListener(clickListener_t * clickListener)
{
    free(clickListener->callbackArgs);
    free(clickListener);
}


/* return values: 
-1.. if there is an error somewhere
0... to exit the program
1... to do nothing in main
*/
int handleEvent(
    SDL_Event event, 
    clickListener_t * clickListeners
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
