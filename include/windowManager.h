#ifndef _WINDOW_MANAGER_H_
#define _WINDOW_MANAGER_H_

#include <SDL2/SDL.h>
#include "texturePicker.h"
#include "constants.h"
#include "typedefs.h"
#include "map.h"
#include "eraser.h"
#include "currentTextureInfo.h"
#include "mapFileGenerator.h"
#include "textInputBox.h"

int initMainWindow(windowAndRenderer_t * mainWindow);

int createModules(
    windowAndRenderer_t * mainWindow,
    clickListener_t * clickListeners,
    appContext_t * appContext
);

#endif
