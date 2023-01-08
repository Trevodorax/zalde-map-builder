#include "eraser.h"

int createEraserButton(
    appContext_t * appContext, 
    SDL_Renderer * renderer, 
    clickListener_t * clickListeners
)
{
    SDL_Texture * buttonTexture;
    startErasingArgs_t * startErasingArgs = malloc(sizeof(startErasingArgs_t));
    if(startErasingArgs == NULL)
    {
        fprintf(stderr, "malloc error");
        return -1;
    }

    startErasingArgs->appContext = appContext;

    buttonTexture = getImageTexture(renderer, "assets/buttons/delete-icon.bmp");

    if(createButton(
        BUTTON_TYPE_ERASE_BUTTON,
        (SDL_Rect) {0, 0, 64, 64},
        startErasing,
        startErasingArgs,
        buttonTexture,
        clickListeners,
        renderer
    ) != 0)
    {
        fprintf(stderr, "createButton error");
        return -1;
    }
    return 0;
}

void startErasing(void * voidArgs)
{ 
    startErasingArgs_t * args = (startErasingArgs_t *) voidArgs;

    args->appContext->isErasing = 1;
    args->appContext->currentTileLetter = 'A';
    args->appContext->currentTileNumber = 0;
}
