#ifndef _WINDOW_MANAGER_H_
#define _WINDOW_MANAGER_H_

#include <SDL2/SDL.h>
#include "SDLUtils.h"
#include "utils.h"
#include "button.h"

int initMainWindow(windowAndRenderer_t * mainWindow);

int createTexturePicker(
    windowAndRenderer_t * mainWindow, 
    clickListener_t ** clickListeners, 
    size_t * clickListenersSize
);

int createTexturePickerCategory(
    SDL_Renderer * renderer, 
    const char categoryLetter,
    clickListener_t ** clickListeners,
    size_t * clickListenersSize
);

int buttonCallback();

#endif
