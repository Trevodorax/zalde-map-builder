#include "main.h"

char currentTileLetter;
unsigned short currentTileNumber;
char tilePickerLetter;

int main(int argc, char *argv[])
{
    // main window of the program
    windowAndRenderer_t mainWindow;
    // return value of the main function
    int exitStatus = EXIT_FAILURE;
    // current event in each iteration of the program loop
    SDL_Event event;
    // array of click listeners
    // TODO : use a linked list instead of an array 
    clickListener_t * clickListeners = malloc(0);
    // File letter for the texture we are on
    tilePickerLetter = 'A';

    if(clickListeners == NULL)
    {
        fprintf(stderr, "malloc error : %s", SDL_GetError());
        goto Quit;
    }
    size_t clickListenersSize = 0;


    if(SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        fprintf(stderr, "Error SDL_Init : %s", SDL_GetError());
        goto Quit;
    }

    if(initMainWindow(&mainWindow) != 0)
    {
        goto Quit;
    }

    createTexturePicker(&mainWindow, &clickListeners, &clickListenersSize, tilePickerLetter);
    

    // main loop
    while(1) 
    {
        
        printf("\nCurrent tile: %c%hu", currentTileLetter, currentTileNumber);
        printf("\nCurrent texture picker: %c", tilePickerLetter);
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
        SDL_RenderPresent(mainWindow.renderer);
        SDL_Delay(LOOP_DELAY_MS);
    }

    
    
    exitStatus = EXIT_SUCCESS;

Quit:
    if(mainWindow.window)
    {
        SDL_DestroyWindow(mainWindow.window);
    }
    if(mainWindow.renderer)
    {
        SDL_DestroyRenderer(mainWindow.renderer);
    }
    
    for(int i = 0; i < clickListenersSize; i++)
    {
        free(clickListeners[i].callbackArgs);
    }
    free(clickListeners);

    SDL_Quit();

    return exitStatus;
}
