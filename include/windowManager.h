#ifndef _WINDOW_MANAGER_H_
#define _WINDOW_MANAGER_H_

#include <SDL2/SDL.h>
#include "SDLUtils.h"
#include "utils.h"

int initMainWindow(windowAndRenderer_t * mainWindow);

int initTexturePicker(windowAndRenderer_t mainWindow);

#endif
