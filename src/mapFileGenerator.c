#include "mapFileGenerator.h"
#include "obstacleTextures.h"

int createMapSaver(
    clickListener_t * clickListeners,
    SDL_Renderer * renderer,
    appContext_t * appContext
)
{
    SDL_Texture * buttonTexture;
    saveMapArgs_t * saveMapArgs = malloc(sizeof(saveMapArgs_t));
    if(saveMapArgs == NULL)
    {
        fprintf(stderr, "\nmalloc error");
        return -1;
    }

    saveMapArgs->appContext = appContext;

    buttonTexture = getImageTexture(renderer, "assets/buttons/save.bmp");

    if(createButton(
        BUTTON_TYPE_SAVE_BUTTON,
        (SDL_Rect) {SAVE_BUTTON_POS_X, SAVE_BUTTON_POS_Y, SAVE_BUTTON_SIZE, SAVE_BUTTON_SIZE},
        saveMap,
        saveMapArgs,
        buttonTexture,
        clickListeners,
        renderer
    ) != 0)
    {
        fprintf(stderr, "\ncreateButton error");
        return -1;
    }

    return 0;
}

void saveMap(void * voidArgs)
{
    saveMapArgs_t * args = (saveMapArgs_t *) voidArgs;

    if(generateMapFile(args->appContext->map) != 0)
    {
        fprintf(stderr, "\ngenerateMapFile error");
    }

    return;
}

int generateMapFile(
    mapTile_t map[MAP_SIZE][MAP_SIZE]
)
{
    FILE * mapFile = fopen("maps/map.zalde", "w");
    if(mapFile == NULL)
    {
        fprintf(stderr, "\nfopen error");
        return -1;
    }

    for(int y = 0; y < MAP_SIZE; y++)
    {
        for(int x = 0; x < MAP_SIZE; x++)
        {
            addTileToFile(map[x][y], mapFile);
        }
        fprintf(mapFile, "\n");
    }

    return 0;
}

void addTileToFile(mapTile_t tile, FILE * mapFile)
{
    fprintf(
        mapFile, 
        "%c%hu,%c%hu,%c;", 
        tile.primaryTexture.letter, 
        tile.primaryTexture.number,
        tile.secondaryTexture.letter,
        tile.secondaryTexture.number,
        getTileChar(tile)
    );
}

char getTileChar(mapTile_t tile)
{
    size_t i;
    size_t obstacleTexturesSize = sizeof(obstacleTextures) / sizeof(obstacleTextures[0]);
    for(i = 0; i < obstacleTexturesSize; i++)
    {
        if(tile.isLinkedMap)
        {
            return 'm';
        }

        if(
            tile.primaryTexture.letter == obstacleTextures[i].letter &&
            tile.primaryTexture.number == obstacleTextures[i].number
        )
        {
            return 'o';
        }
    }

    return 'f';
}
