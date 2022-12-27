#include "clickListeners.h"

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
    char type,
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
    newClickListener->type = type;
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

// free a click listener
void freeClickListener(clickListener_t * clickListener)
{
    free(clickListener->callbackArgs);
    free(clickListener);
}

// remove all click listeners of a given type
int removeClickListenersByType(
    char type,
    clickListener_t * clickListeners
)
{
    clickListener_t * currentClickListener = clickListeners;
    while(currentClickListener->next != NULL)
    {
        if(currentClickListener->next->type == type)
        {
            clickListener_t * nextClickListener = currentClickListener->next->next;
            freeClickListener(currentClickListener->next);
            currentClickListener->next = nextClickListener;
        } else {
            currentClickListener = currentClickListener->next;
        }
    }
    return 0;
}