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
    

    for(i = 0; i < TEXTURE_PICKER_TILES_PER_ROW; i++)
    {
        for(j = 0; j < TEXTURE_PICKER_TILES_PER_ROW; j++)
        {
            switch(
                createTile(
                    renderer,
                    appContext,
                    textureFileNumber,
                    clickListeners,
                    TEXTURE_PICKER_TILE_SIZE,
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

    setCurrentTileArgs->tileLetter = appContext->texturePickerLetter;
    setCurrentTileArgs->tileNumber = textureFileNumber;
    setCurrentTileArgs->appContext = appContext;

    tileFileName = getTileFileName(appContext->texturePickerLetter, textureFileNumber);

    tileTexture = getImageTexture(renderer, tileFileName);
    if(!tileTexture)
    {
        return 1;
    }

    SDL_Rect buttonRectTile = {texturePickerPosition.x + (yTileIndex * tileSize), texturePickerPosition.y + (xTileIndex * tileSize), tileSize - TEXTURE_PICKER_TILE_SPACING, tileSize - TEXTURE_PICKER_TILE_SPACING};
    createButton(
        BUTTON_TYPE_TEXTURE_PICKER,
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

    appContext->isErasing = 0;
    
    return;
}
