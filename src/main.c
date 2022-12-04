#include "main.h"

int main(int argc, char *argv[])
{
    // main window of the program
    WindowAndRenderer_t window1;
    // return value of the main function
    int exitStatus = EXIT_FAILURE;
    // current event in each iteration of the program loop
    SDL_Event event;
    // array of click listeners
    clickListener_t * clickListeners = malloc(0);


    if(0 != SDL_Init(SDL_INIT_VIDEO))
    {
        fprintf(stderr, "Erreur SDL_Init : %s", SDL_GetError());
        exitStatus = EXIT_FAILURE;
        goto Quit;
    }

    if(initMainWindow(&window1) != 0)
    {
        goto Quit;
    }

    // main loop
    while(1) 
    {
        while(SDL_PollEvent(&event)) 
        {
            switch(handleEvent(event))
            {
                // there was an error during the event handling
                case -1:
                    exitStatus = EXIT_FAILURE;
                    goto Quit;
                // event to exit the program
                case 0:
                    goto Quit;
                // the event was handled and there is nothing more to do with it
                case 1:
                    continue;
                // somehow, the function returned something else
                default:
                    continue;
            }
        }
        SDL_RenderPresent(window1.renderer);
        SDL_Delay(50);
    }

    free(clickListeners);

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
    SDL_Quit();
    return exitStatus;
}
