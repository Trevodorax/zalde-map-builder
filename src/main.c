#include "main.h"

int main(int argc, char *argv[])
{
    WindowAndRenderer_t window1;
    int exitStatus = EXIT_FAILURE;

    if(0 != SDL_Init(SDL_INIT_VIDEO))
    {
        fprintf(stderr, "Erreur SDL_Init : %s", SDL_GetError());
        goto Quit;
    }

    if(initMainWindow(&window1) != 0)
    {
        goto Quit;
    }

    // main loop
    while(1) {
        SDL_Event event;
        while(SDL_PollEvent(&event)) {
            if(event.type == SDL_QUIT) {
                goto Quit;
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
    SDL_Quit();
    return exitStatus;
}
