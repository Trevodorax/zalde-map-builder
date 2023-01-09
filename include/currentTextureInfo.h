#ifndef _CURRENT_TEXTURE_INFO_H_
#define _CURRENT_TEXTURE_INFO_H_

#include <SDL2/SDL.h>
#include "constants.h"
#include "typedefs.h"
#include "SDLUtils.h"
#include "utils.h"

int createCurrentTextureInfo(SDL_Renderer * renderer);

int updateCurrentTextureInfo(
    SDL_Renderer * renderer,
    char letter,
    unsigned short number
);

#endif
