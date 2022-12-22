#include "texturePicker.h"

int createTexturePickerCategory(
    SDL_Renderer * renderer, 
    const char categoryLetter,
    clickListener_t ** clickListeners,
    size_t * clickListenersSize,
    size_t texturePickerSize,
    SDL_Point texturePickerPosition
)
{
    int i, j;
    unsigned short textureFileNumber = 1;
    
    // calculate the size of each tile
    size_t tileSize = texturePickerSize / 10;

    for(i = 0; i < 10; i++)
    {
        for(j = 0; j < 10; j++)
        {
            if(createTile(
                renderer,
                categoryLetter,
                textureFileNumber,
                clickListeners,
                clickListenersSize,
                tileSize,
                texturePickerPosition,
                i,
                j
            ) != 0) return -1;

            textureFileNumber++;
        }
    }

    return 0;
}

int createTile(
    SDL_Renderer * renderer,
    char categoryLetter,
    unsigned short textureFileNumber,
    clickListener_t ** clickListeners,
    size_t * clickListenersSize,
    size_t tileSize,
    SDL_Point texturePickerPosition,
    int xTileIndex,
    int yTileIndex
)
{
    char * tileFileName;
    SDL_Texture * tileTexture;
    setCurrentTileArgs_t * tileInfos = malloc(sizeof(setCurrentTileArgs_t));
    if(tileInfos == NULL)
    {
        fprintf(stderr, "malloc error");
        return -1;
    }

    tileInfos->tileLetter = categoryLetter;
    tileInfos->tileNumber = textureFileNumber;

    tileFileName = getTileFileName(categoryLetter, textureFileNumber);

    // start using the file name here
    tileTexture = getImageTexture(renderer, tileFileName);
    if(!tileTexture)
    {
        return 0;
    }

    SDL_Rect buttonRectTile = {texturePickerPosition.x + (yTileIndex * tileSize), texturePickerPosition.y + (xTileIndex * tileSize), tileSize, tileSize};
    createButton(
        buttonRectTile,
        setCurrentTile,
        tileInfos,
        tileTexture,
        clickListeners,
        clickListenersSize,
        renderer
    );

    // stop using the file name here
    SDL_DestroyTexture(tileTexture);
    free(tileFileName);

    textureFileNumber++;

    return 0;
}

int createNavigation(
    SDL_Renderer * renderer,
    clickListener_t ** clickListeners,
    size_t * clickListenersSize,
    SDL_Point navigationPosition
)
{
    SDL_Texture * leftButtonTexture;
    SDL_Texture * rightButtonTexture;

    leftButtonTexture = getImageTexture(renderer, "assets/buttons/left.bmp");
    rightButtonTexture = getImageTexture(renderer, "assets/buttons/right.bmp");

    if(!leftButtonTexture || !rightButtonTexture)
    {
        return -1;
    }

    if(createNavigationButton(
        renderer,
        (SDL_Rect) {navigationPosition.x, navigationPosition.y, 50, 50},
        leftButtonTexture,
        clickListeners,
        clickListenersSize,
        'l'
    ) != 0 ) return -1;

    if(createNavigationButton(
        renderer,
        (SDL_Rect) {navigationPosition.x + 60, navigationPosition.y, 50, 50},
        rightButtonTexture,
        clickListeners,
        clickListenersSize,
        'r'
    ) != 0 ) return -1;

    return 0;
}


int createNavigationButton(
    SDL_Renderer * renderer,
    SDL_Rect buttonRect,
    SDL_Texture * buttonTexture,
    clickListener_t ** clickListeners,
    size_t * clickListenersSize,
    char navDirection
)
{
    setTexturePickerCategoryArgs_t * callbackArgs = malloc(sizeof(setTexturePickerCategoryArgs_t));
    if(callbackArgs == NULL)
    {
        fprintf(stderr, "malloc error");
        return -1;
    }
    callbackArgs->direction = navDirection;

    if(createButton(
        buttonRect,
        setTexturePickerCategory,
        callbackArgs,
        buttonTexture,
        clickListeners,
        clickListenersSize,
        renderer
    ) != 0) return -1;

    SDL_DestroyTexture(buttonTexture);

    return 0;
}

void setCurrentTile(
    void * tileInfos
)
{
    setCurrentTileArgs_t * tileInfosStruct = (setCurrentTileArgs_t *) tileInfos;

    extern char currentTileLetter;
    currentTileLetter = tileInfosStruct->tileLetter;
    extern unsigned short currentTileNumber;
    currentTileNumber = tileInfosStruct->tileNumber;
    
    return;
}


void setTexturePickerCategory(
    void * args
)
{
    setTexturePickerCategoryArgs_t * callbackArgs = (setTexturePickerCategoryArgs_t *) args;

    extern char tilePickerLetter;
    if(callbackArgs->direction == 'l')
    {
        if(tilePickerLetter == 'A')
        {
            tilePickerLetter = 'Z';
        }
        else
        {
            tilePickerLetter--;
        }
    }
    else if(callbackArgs->direction == 'r')
    {
        if(tilePickerLetter == 'Z')
        {
            tilePickerLetter = 'A';
        }
        else
        {
            tilePickerLetter++;
        }
    }
    else
    {
        fprintf(stderr, "invalid direction");
    }

    return;
}
