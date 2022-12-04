#include "windowManager.h"

#define WINDOW_SIZE 512

int initMainWindow(WindowAndRenderer_t * mainWindow) {
    if(initWindowAndRenderer(mainWindow, "Map builder", WINDOW_SIZE) != 0) {
        return -1;
    }

    SDL_Color red = {255, 0, 0, 255};

    if(setBackgroundColor(mainWindow->renderer, red) != 0) {
        return -1;
    }

    SDL_RenderPresent(mainWindow->renderer);
    return 0;
}
