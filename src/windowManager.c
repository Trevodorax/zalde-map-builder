#include "windowManager.h"

#define WINDOW_SIZE_X 1025
#define WINDOW_SIZE_Y 512

int initMainWindow(windowAndRenderer_t * mainWindow) {
    if(initWindowAndRenderer(mainWindow, "Map builder", WINDOW_SIZE_X, WINDOW_SIZE_Y) != 0) {
        return -1;
    }

    SDL_Color red = {255, 0, 0, 255};

    if(setBackgroundColor(mainWindow->renderer, red) != 0) {
        return -1;
    }

    SDL_RenderPresent(mainWindow->renderer);
    return 0;
}
