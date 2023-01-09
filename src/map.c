#include "map.h"

void initMap(mapTile_t map[MAP_SIZE][MAP_SIZE])
{
    size_t x, y;

    for(x = 0; x < MAP_SIZE; x++) {
        for(y = 0; y < MAP_SIZE; y++) {
            map[y][x].primaryTexture.letter = EMPTY_TEXTURE_CHAR;
            map[y][x].primaryTexture.number = EMPTY_TEXTURE_NUMBER;
            map[y][x].secondaryTexture.letter = EMPTY_TEXTURE_CHAR;
            map[y][x].secondaryTexture.number = EMPTY_TEXTURE_NUMBER;
        }
    }
}

void printMap(mapTile_t map[MAP_SIZE][MAP_SIZE])
{
    size_t x, y;

    printf("\n\n");
    printf("--------------------------------------------------------------------------------------------------------------------------------\n");

    for(x = 0; x < MAP_SIZE; x++) {
        for(y = 0; y < MAP_SIZE; y++) {
            printf(" %c%hu ", map[y][x].primaryTexture.letter, map[y][x].primaryTexture.number);
            printf("%c%hu |", map[y][x].secondaryTexture.letter, map[y][x].secondaryTexture.number);
        }
        printf("\n--------------------------------------------------------------------------------------------------------------------------------\n");
    }
    printf("\n\n");
}

int createMap(
    clickListener_t * clickListeners,
    SDL_Renderer * renderer,
    appContext_t * appContext
)
{
    size_t x, y;

    for(x = 0; x < MAP_SIZE; x++) {
        for(y = 0; y < MAP_SIZE; y++) {
            if(createMapTile(
                y,
                x,
                clickListeners,
                renderer,
                appContext
            ) != 0)
            {
                fprintf(stderr, "createMapTile error");
                return -1;
            }
        }
    }

    return 0;
}

int createMapTile(
    size_t x,
    size_t y,
    clickListener_t * clickListeners, 
    SDL_Renderer * renderer,
    appContext_t * appContext
)
{
    setMapTileArgs_t * setCurrentTileArgs = malloc(sizeof(setMapTileArgs_t));
    if(setCurrentTileArgs == NULL)
    {
        fprintf(stderr, "malloc error");
        return -1;
    }

    setCurrentTileArgs->x = x;
    setCurrentTileArgs->y = y;
    setCurrentTileArgs->renderer = renderer;
    setCurrentTileArgs->appContext = appContext;

    SDL_Rect tileRect = getMapTileRect(x, y);

    if(createButton(
        BUTTON_TYPE_MAP_TILE,
        tileRect,
        setMapTile,
        setCurrentTileArgs,
        NULL,
        clickListeners,
        renderer
    ) != 0)
    {
        fprintf(stderr, "createButton error");
        return -1;
    }

    return 0;
}

void setMapTile(void * callbackArgs)
{
    setMapTileArgs_t * args = (setMapTileArgs_t *) callbackArgs;

    appContext_t * appContext = args->appContext;

    // exit if no tile was selected
    if(appContext->currentTileLetter == EMPTY_TEXTURE_CHAR && appContext->currentTileNumber == 0 && !appContext->isErasing)
    {
        return;
    }

    if(appContext->isErasing)
    {
        appContext->map[args->x][args->y].primaryTexture.letter = EMPTY_TEXTURE_CHAR;
        appContext->map[args->x][args->y].primaryTexture.number = EMPTY_TEXTURE_NUMBER;
        appContext->map[args->x][args->y].secondaryTexture.letter = EMPTY_TEXTURE_CHAR;
        appContext->map[args->x][args->y].secondaryTexture.number = EMPTY_TEXTURE_NUMBER;

        if(updateMapTileTexture(
            args->x,
            args->y,
            EMPTY_TEXTURE_CHAR,
            0,
            args->renderer
        ))
        return;
    }

    int mapTileType = getMapTileType(appContext->map[args->x][args->y]);

    switch(mapTileType)
    {
        case 0:
            appContext->map[args->x][args->y].primaryTexture.letter = appContext->currentTileLetter;
            appContext->map[args->x][args->y].primaryTexture.number = appContext->currentTileNumber;
            break;
        case 1:
            appContext->map[args->x][args->y].secondaryTexture.letter = appContext->currentTileLetter;
            appContext->map[args->x][args->y].secondaryTexture.number = appContext->currentTileNumber;
            break;
        case 2:
            return;
    }

    if(updateMapTileTexture(
        args->x,
        args->y,
        appContext->currentTileLetter, 
        appContext->currentTileNumber, 
        args->renderer
    ) != 0)
    {
        fprintf(stderr, "updateMapTileTexture error");
        return;
    }
}

// 0 - everything is empty
// 1 - secondary is empty
// 2 - tile full
int getMapTileType(mapTile_t mapTile)
{
    if(mapTile.primaryTexture.letter == EMPTY_TEXTURE_CHAR && mapTile.primaryTexture.number == EMPTY_TEXTURE_NUMBER)
    {
        return 0;
    }

    if(mapTile.secondaryTexture.letter == EMPTY_TEXTURE_CHAR && mapTile.secondaryTexture.number == EMPTY_TEXTURE_NUMBER)
    {
        return 1;
    }

    return 2;
}

SDL_Rect getMapTileRect(
    size_t x, 
    size_t y
)
{
    SDL_Rect rect;

    rect.x = MAP_SECTION_POS_X + x * MAP_TILE_SIZE;
    rect.y = MAP_SECTION_POS_Y + y * MAP_TILE_SIZE;
    rect.w = MAP_TILE_SIZE;
    rect.h = MAP_TILE_SIZE;

    return rect;
}

int updateMapTileTexture(
    size_t x, 
    size_t y, 
    char letter, 
    unsigned short number,
    SDL_Renderer * renderer
)
{
    SDL_Rect tileRect = getMapTileRect(x, y);

    // if erasing
    if(letter == EMPTY_TEXTURE_CHAR && number == EMPTY_TEXTURE_NUMBER)
    {
        if(SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255) != 0)
        {
            fprintf(stderr, "SDL_SetRenderDrawColor error: %s", SDL_GetError());
            return -1;
        }

        if(SDL_RenderFillRect(renderer, &tileRect) != 0)
        {
            fprintf(stderr, "SDL_RenderFillRect error: %s", SDL_GetError());
            return -1;
        }

        return 0;
    }

    SDL_Texture * tileTexture = getImageTexture(
        renderer, 
        getTileFileName(
            letter,
            number
        )
    );
    if(!tileTexture)
    {
        return -1;
    }

    if(SDL_RenderCopy(renderer, tileTexture, NULL, &tileRect) != 0)
    {
        fprintf(stderr, "SDL_RenderCopy error: %s", SDL_GetError());
        return -1;
    }

    return 0;
}
