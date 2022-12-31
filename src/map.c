#include "map.h"

void initMap(texture_t map[MAP_SIZE][MAP_SIZE])
{
    size_t i, j;

    for(i = 0; i < MAP_SIZE; i++) {
        for(j = 0; j < MAP_SIZE; j++) {
            map[i][j].letter = 'A';
            map[i][j].number = 0;
        }
    }
}

void printMap(texture_t map[MAP_SIZE][MAP_SIZE])
{
    size_t i, j;

    printf("\n\n");
    for(i = 0; i < MAP_SIZE; i++) {
        for(j = 0; j < MAP_SIZE; j++) {
            printf("%c%hu ", map[i][j].letter, map[i][j].number);
        }
        printf("\n");
    }
    printf("\n\n");
}

int createMap(
    clickListener_t * clickListeners,
    SDL_Renderer * renderer,
    appContext_t * appContext
)
{
    size_t i, j;

    for(i = 0; i < MAP_SIZE; i++) {
        for(j = 0; j < MAP_SIZE; j++) {
            if(createMapTile(
                i,
                j,
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

    appContext->map[args->x][args->y].letter = appContext->currentTileLetter;
    appContext->map[args->x][args->y].number = appContext->currentTileNumber;
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
