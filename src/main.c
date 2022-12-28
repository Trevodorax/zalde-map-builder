#include "main.h"

int main(int argc, char *argv[])
{
    // main window of the program
    windowAndRenderer_t mainWindow;
    // return value of the main function
    int exitStatus = EXIT_FAILURE;
    // current event in each iteration of the program loop
    SDL_Event event;
    // array of click listeners
    clickListener_t * clickListeners = initClickListeners();

    appContext_t appContext;
    appContext.currentTileLetter = '0';
    appContext.currentTileNumber = 0;
    appContext.texturePickerLetter = 'A';

    if(clickListeners == NULL)
    {
        fprintf(stderr, "malloc error : %s", SDL_GetError());
        goto Quit;
    }

    if(SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        fprintf(stderr, "Error SDL_Init : %s", SDL_GetError());
        goto Quit;
    }

    if(initMainWindow(&mainWindow) != 0)
    {
        goto Quit;
    }

    createTexturePicker(&mainWindow, clickListeners, &appContext);
    

    // main loop
    while(1) 
    {
        // print the app context
        printf("\n\nApp context :");
        printf("\ncurrentTileLetter: %c", appContext.currentTileLetter);
        printf("\ncurrentTileNumber: %d", appContext.currentTileNumber);
        printf("\ntexturePickerLetter: %c", appContext.texturePickerLetter);

        while(SDL_PollEvent(&event))
        {
            switch(handleEvent(event, clickListeners))
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
    
    freeClickListeners(clickListeners);

    SDL_Quit();

    return exitStatus;
}
