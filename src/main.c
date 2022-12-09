#include "main.h"

char currentTileLetter;
unsigned short currentTileNumber;

int main(int argc, char *argv[])
{
    // main window of the program
    windowAndRenderer_t window1;
    // return value of the main function
    int exitStatus = EXIT_FAILURE;
    // current event in each iteration of the program loop
    SDL_Event event;
    // array of click listeners
    clickListener_t * clickListeners = malloc(0);
    if(clickListeners == NULL)
    {
        fprintf(stderr, "malloc error : %s", SDL_GetError());
        goto Quit;
    }
    size_t clickListenersSize = 0;


    if(SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        fprintf(stderr, "Erreur SDL_Init : %s", SDL_GetError());
        goto Quit;
    }

    if(initMainWindow(&window1) != 0)
    {
        goto Quit;
    }


    createTexturePicker(&window1, &clickListeners, &clickListenersSize);

    // main loop
    while(1) 
    {
        printf("\nCurrent tile: %c%hu", currentTileLetter, currentTileNumber);
        while(SDL_PollEvent(&event)) 
        {
            switch(handleEvent(event, clickListeners, clickListenersSize))
            {
                // there was an error during the event handling
                case -1:
                    goto Quit;
                // event to exit the program
                case 0:
                    exitStatus = EXIT_SUCCESS;
                    goto Quit;
                // the event was handled and there is nothing more to do with it
                case 1:
                    break;
                // somehow, the function returned something else
                default:
                    break;
            }
        }
        SDL_RenderPresent(window1.renderer);
        SDL_Delay(LOOP_DELAY_MS);
    }

    
    
    exitStatus = EXIT_SUCCESS;

Quit:
    if(window1.window)
    {
        SDL_DestroyWindow(window1.window);
    }
    if(window1.renderer)
    {
        SDL_DestroyRenderer(window1.renderer);
    }

    free(clickListeners);

    SDL_Quit();

    return exitStatus;
}
