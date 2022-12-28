#include "texturePicker.h"

// create the texture tiles for a category
int createTexturePickerCategory(
    SDL_Renderer * renderer, 
    appContext_t * appContext,
    clickListener_t * clickListeners,
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
            switch(
                createTile(
                    renderer,
                    appContext,
                    appContext->texturePickerLetter,
                    textureFileNumber,
                    clickListeners,
                    tileSize,
                    texturePickerPosition,
                    i,
                    j
                )
            )
            {
                case -1:
                    return -1;
                case 1:
                    return 0;
            }

            textureFileNumber++;
        }
    }

    return 0;
}


// create a tile given a category and a texture file number
int createTile(
    SDL_Renderer * renderer,
    appContext_t * appContext,
    char categoryLetter,
    unsigned short textureFileNumber,
    clickListener_t * clickListeners,
    size_t tileSize,
    SDL_Point texturePickerPosition,
    int xTileIndex,
    int yTileIndex
)
{
    char * tileFileName;
    SDL_Texture * tileTexture;
    setCurrentTileArgs_t * setCurrentTileArgs = malloc(sizeof(setCurrentTileArgs_t));
    if(setCurrentTileArgs == NULL)
    {
        fprintf(stderr, "malloc error");
        return -1;
    }

    setCurrentTileArgs->tileLetter = categoryLetter;
    setCurrentTileArgs->tileNumber = textureFileNumber;
    setCurrentTileArgs->appContext = appContext;

    tileFileName = getTileFileName(categoryLetter, textureFileNumber);

    tileTexture = getImageTexture(renderer, tileFileName);
    if(!tileTexture)
    {
        return 1;
    }

    SDL_Rect buttonRectTile = {texturePickerPosition.x + (yTileIndex * tileSize), texturePickerPosition.y + (xTileIndex * tileSize), tileSize, tileSize};
    createButton(
        't',
        buttonRectTile,
        setCurrentTile,
        setCurrentTileArgs,
        tileTexture,
        clickListeners,
        renderer
    );

    SDL_DestroyTexture(tileTexture);
    free(tileFileName);

    textureFileNumber++;

    return 0;
}


// set the global value of the current tile
void setCurrentTile(
    void * args
)
{
    setCurrentTileArgs_t * tileInfosStruct = (setCurrentTileArgs_t *) args;
    appContext_t * appContext = tileInfosStruct->appContext;

    appContext->currentTileLetter = tileInfosStruct->tileLetter;
    appContext->currentTileNumber = tileInfosStruct->tileNumber;
    
    return;
}
