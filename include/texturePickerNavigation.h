#ifndef _TEXTURE_PICKER_NAVIGATION_H_
#define _TEXTURE_PICKER_NAVIGATION_H_

#include <SDL2/SDL.h>
#include "typedefs.h"
#include "constants.h"
#include "SDLUtils.h"
#include "button.h"
#include "texturePicker.h"

int createNavigation(
    SDL_Renderer * renderer,
    clickListener_t * clickListeners,
    appContext_t * appContext,
    SDL_Point navigationPosition
);

int createNavigationButton(
    SDL_Renderer * renderer,
    SDL_Rect buttonRect,
    SDL_Texture * buttonTexture,
    clickListener_t * clickListeners,
    char navDirection,
    appContext_t * appContext
);

void setTexturePickerCategory(
    void * args
);

void setCategoryLetter(
    char direction,
    appContext_t * appContext
);

#endif
