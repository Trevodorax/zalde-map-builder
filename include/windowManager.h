#ifndef _WINDOW_MANAGER_H_
#define _WINDOW_MANAGER_H_

#include <SDL2/SDL.h>
#include "texturePicker.h"
#include "constants.h"

int initMainWindow(windowAndRenderer_t * mainWindow);

int createTexturePicker(
    windowAndRenderer_t * mainWindow,
    clickListener_t * clickListeners,
    char * texturePickerCategoryLetter
);

#endif
