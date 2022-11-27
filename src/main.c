#include "../include/main.h"

int main(int argc, char *argv[])
{
    printHi();
    WindowAndRenderer_t window1;
    int exitStatus = EXIT_FAILURE;

    if(0 != SDL_Init(SDL_INIT_VIDEO))
    {
        fprintf(stderr, "Erreur SDL_Init : %s", SDL_GetError());
        goto Quit;
    }

    if(initWindowAndRenderer(&window1, "Window 1", WINDOW_SIZE) != 0) {
        goto Quit;
    }

    if(setBackgroundColor(window1.renderer, red) != 0) {
        goto Quit;
    }

    SDL_RenderPresent(window1.renderer);

    SDL_Delay(3000);
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
