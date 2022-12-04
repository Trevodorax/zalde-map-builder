# include "events.h"

/* return values: 
-1.. if there is an error somewhere
0... to exit the program
1... to do nothing in main
*/

int handleEvent(SDL_Event event) 
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
                // key that is not handled
                default:
                    printf("\nKey pressed: %d", event.key.keysym.sym);
            }
        // handle mouse events
        case SDL_MOUSEBUTTONDOWN:
            switch(event.button.button) 
            {

                // handle left click
                case SDL_BUTTON_LEFT:
                    // get the coords of click
                    printf("\nLeft click at (%d, %d)", event.button.x, event.button.y);
                    return 1;
                // unhandled mouse event
                default:
                    return 1;
            }
        // unhandled event type
        default:
            return 1;
    }
    return 1;
}
