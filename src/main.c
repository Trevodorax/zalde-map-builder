#include "main.h"

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

    /* ----- TESTING ADDING BUTTON FUNCTIONNALITY ----- */

    SDL_Rect buttonRect = {0, 0, 100, 100};
    int testFunc(int a, int b) {
        printf("\ntestFunc called with %d and %d", a, b); 
        return 0;
    }
    SDL_Color buttonColor = {0, 255, 0, 255};


    if(createButton(
        buttonRect, 
        testFunc, 
        buttonColor, 
        &clickListeners,
        &clickListenersSize,
        window1.renderer
    ) != 0)
    {
        goto Quit;
    }

    /* ----- END OF TEST ----- */

    // main loop
    while(1) 
    {
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
                    fprintf(stderr, "GG romain, you fucked up");    
                    break;
            }
        }
        SDL_RenderPresent(window1.renderer);
        SDL_Delay(50);
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
