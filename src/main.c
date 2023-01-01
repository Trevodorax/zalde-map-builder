#include "main.h"

int main(int argc, char *argv[])
{
    windowAndRenderer_t mainWindow;
    
    SDL_Event event;
    clickListener_t * clickListeners = initClickListeners();

    appContext_t appContext;
    appContext.currentTileLetter = '0';
    appContext.currentTileNumber = 0;
    appContext.texturePickerLetter = 'A';

    initMap(appContext.map);

    if(clickListeners == NULL)
    {
        fprintf(stderr, "malloc error : %s", SDL_GetError());
        return EXIT_FAILURE;
    }

    if(SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        fprintf(stderr, "Error SDL_Init : %s", SDL_GetError());
        freeClickListeners(clickListeners);
        return EXIT_FAILURE;
    }

    if(initMainWindow(&mainWindow) != 0)
    {
        freeClickListeners(clickListeners);
        SDL_Quit();
        return EXIT_FAILURE;
    }

    if(createTexturePicker(
        &mainWindow,
        clickListeners,
        &appContext
    ) != 0)
    {
        freeClickListeners(clickListeners);
        freeWindowAndRenderer(&mainWindow);
        SDL_Quit();
        return EXIT_FAILURE;
    }


    while(1) 
    {
        printMap(appContext.map);
        while(SDL_PollEvent(&event))
        {
            switch(handleEvent(event, clickListeners))
            {
                // there was an error during the event handling
                case -1:
                    freeWindowAndRenderer(&mainWindow);
                    freeClickListeners(clickListeners);
                    SDL_Quit();
                    return EXIT_FAILURE;
                // event to exit the program
                case 0:
                    freeWindowAndRenderer(&mainWindow);
                    freeClickListeners(clickListeners);
                    SDL_Quit();
                    return EXIT_SUCCESS;
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

    return EXIT_SUCCESS;
}
