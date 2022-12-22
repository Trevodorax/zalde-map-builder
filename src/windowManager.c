#include "windowManager.h"

#define WINDOW_SIZE_X 1280
#define WINDOW_SIZE_Y 660

#define TILE_SECTION_POS_X 50
#define TILE_SECTION_POS_Y 50
#define TEXTURE_PICKER_SIZE 512

int initMainWindow(windowAndRenderer_t * mainWindow) 
{
    if(initWindowAndRenderer(mainWindow, "Map builder", WINDOW_SIZE_X, WINDOW_SIZE_Y) != 0) {
        return -1;
    }

    SDL_Color backgroundColor = {255, 255, 255, 255};

    if(setBackgroundColor(mainWindow->renderer, backgroundColor) != 0) {
        return -1;
    }

    return 0;
}



int createTexturePicker(
    windowAndRenderer_t * mainWindow,
    clickListener_t ** clickListeners,
    size_t * clickListenersSize,
    char textureFileLetter
)
{

    // create the category
    if(createTexturePickerCategory(
        mainWindow->renderer, 
        textureFileLetter, 
        clickListeners, 
        clickListenersSize,
        TEXTURE_PICKER_SIZE,
        (SDL_Point) {TILE_SECTION_POS_X, TILE_SECTION_POS_Y + 60}
    ) != 0) {
        return -1;
    }

    // create the navigation buttons
    createNavigation(
        mainWindow->renderer,
        clickListeners,
        clickListenersSize,
        (SDL_Point) {TILE_SECTION_POS_X, TILE_SECTION_POS_Y}
    );

    return 0;
}
