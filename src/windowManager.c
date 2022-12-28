#include "windowManager.h"


// create the main window and its renderer
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


// create the texture picker and navigation buttons
int createTexturePicker(
    windowAndRenderer_t * mainWindow,
    clickListener_t * clickListeners,
    appContext_t * appContext
)
{

    // create the category
    if(createTexturePickerCategory(
        mainWindow->renderer, 
        appContext, 
        clickListeners, 
        TEXTURE_PICKER_SIZE,
        (SDL_Point) {TILE_SECTION_POS_X, TILE_SECTION_POS_Y + NAVIGATION_BUTTON_SIZE + 10}
    ) != 0) {
        return -1;
    }

    // create the navigation buttons
    createNavigation(
        mainWindow->renderer,
        clickListeners,
        appContext,
        (SDL_Point) {TILE_SECTION_POS_X, TILE_SECTION_POS_Y}
    );

    return 0;
}
