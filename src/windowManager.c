#include "windowManager.h"

#define WINDOW_SIZE_X 1280
#define WINDOW_SIZE_Y 640

int initMainWindow(windowAndRenderer_t * mainWindow) 
{
    if(initWindowAndRenderer(mainWindow, "Map builder", WINDOW_SIZE_X, WINDOW_SIZE_Y) != 0) {
        return -1;
    }

    SDL_Color white = {255, 255, 255, 255};

    if(setBackgroundColor(mainWindow->renderer, white) != 0) {
        return -1;
    }

    SDL_RenderPresent(mainWindow->renderer);
    return 0;
}

int createTexturePicker(
    windowAndRenderer_t * mainWindow, 
    clickListener_t ** clickListeners, 
    size_t * clickListenersSize
) 
{
    
    // variables that compose the texture file name
    char textureFileLetter = 'A';

    // while(textureFileLetter != ('Z' + 1))
    // {
        
        if(createTexturePickerCategory(
            mainWindow->renderer, 
            textureFileLetter, 
            clickListeners, 
            clickListenersSize
        ) != 0) {
            return -1;
        }

        // textureFileLetter++;
    // }

    return 0;
}

int createTexturePickerCategory(
    SDL_Renderer * renderer, 
    const char categoryLetter,
    clickListener_t ** clickListeners,
    size_t * clickListenersSize
)
{
    int i, j;
    unsigned short textureFileNumber = 1;
    char * tileFileName;
    SDL_Texture * tileTexture;

    

    for(i = 0; i < 10; i++)
    {
        for(j = 0; j < 10; j++)
        {
            tileFileName = getTileFileName(categoryLetter, textureFileNumber);

            // start using the file name here
            tileTexture = getImageTexture(renderer, tileFileName);
            if(!tileTexture)
            {
                return 0;
            }

            SDL_Rect buttonRect = {i * 64, j * 64, 64, 64};
            createButton(
                buttonRect,
                buttonCallback,
                tileTexture,
                clickListeners,
                clickListenersSize,
                renderer
            );

            // stop using the file name here
            SDL_DestroyTexture(tileTexture);
            free(tileFileName);

            textureFileNumber++;
        }
    }

    return 0;
}

int buttonCallback()
{
    extern char currentTileLetter;
    currentTileLetter = 'C';
    extern unsigned short currentTileNumber;
    currentTileNumber = 4;
    printf("\n-----Clicked tile");
    return 0;
}
