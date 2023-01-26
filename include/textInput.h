#ifndef _TEXT_INPUT_H_
#define _TEXT_INPUT_H_


#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "utils.h"
#include "typedefs.h"
#include "textInputBox.h"

void initTextInput(
    appContext_t * appContext
);

int handleKeydown(
    SDL_Event event,
    appContext_t * appContext,
    SDL_Renderer * renderer
);

int writeLetter(
    char letter,
    appContext_t * appContext,
    SDL_Renderer * renderer
);

int deleteLetter(
    appContext_t * appContext,
    SDL_Renderer * renderer
    
);

int enterValue(
    appContext_t * appContext,
    SDL_Renderer * renderer
);
#endif