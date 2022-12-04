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

int initTexturesWindow(WindowAndRenderer_t * texturesWindow) {
    if(initWindowAndRenderer(texturesWindow, "Textures", WINDOW_SIZE) != 0) {
        return -1;
    }

    SDL_Color green = {0, 255, 0, 255};

    if(setBackgroundColor(texturesWindow->renderer, green) != 0) {
        return -1;
    }

    SDL_RenderPresent(texturesWindow->renderer);

    return 0;
}
