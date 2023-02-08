#include "loadMap.h"

// loads the given map into the map array and render it
int loadMap(
    mapTile_t map[MAP_SIZE][MAP_SIZE], 
    char * mapName,
    SDL_Renderer * renderer
)
{
    FILE * mapFile = fopen(mapName, "r");
    if(mapFile == NULL)
    {
        fprintf(stderr, "\nfopen error");
        return -1;
    }

    size_t x, y;
    mapTile_t currentLoadedTile;

    char tileDetails;

    for(y = 0; y < MAP_SIZE; y++) {
        for(x = 0; x < MAP_SIZE; x++) {
            if(fscanf(
                mapFile,
                "%c%hu,%c%hu,%c",
                &currentLoadedTile.primaryTexture.letter,
                &currentLoadedTile.primaryTexture.number,
                &currentLoadedTile.secondaryTexture.letter,
                &currentLoadedTile.secondaryTexture.number,
                &tileDetails
            ) != 5)
            {
                fprintf(stderr, "\nfscanf error");
                fclose(mapFile);
                return -1;
            }

            currentLoadedTile.isLinkedMap = tileDetails == 'm' ? 1 : 0; 

            handleLoadedTile(
                map,
                x,
                y,
                currentLoadedTile,
                renderer
            );

            fgetc(mapFile); // skip the semicolon
        }
        fgetc(mapFile); // skip the newline
    }

    fclose(mapFile);
    return 0;
}

// loads a tile, and updates the map array and the renderer
int handleLoadedTile(
    mapTile_t map[MAP_SIZE][MAP_SIZE],
    size_t x,
    size_t y,
    mapTile_t currentLoadedTile,
    SDL_Renderer * renderer
)
{
    if(currentLoadedTile.isLinkedMap)
    {
        map[x][y].isLinkedMap = 1;
    }

    if(isEmptyTexture(currentLoadedTile.primaryTexture))
    {
        return 1;
    }
    
    if(updateMapTileTexture(
        x,
        y,
        currentLoadedTile.primaryTexture.letter, 
        currentLoadedTile.primaryTexture.number,
        renderer
    ) != 0)
    {
        fprintf(stderr, "\nupdateMapTileTexture error");
        return -1;
    }

    map[x][y].primaryTexture = currentLoadedTile.primaryTexture;

    if(isEmptyTexture(currentLoadedTile.secondaryTexture))
    {
        return 1;
    }

    if(updateMapTileTexture(
        x,
        y,
        currentLoadedTile.secondaryTexture.letter, 
        currentLoadedTile.secondaryTexture.number,
        renderer
    ) != 0)
    {
        fprintf(stderr, "\nupdateMapTileTexture error");
        return -1;
    }

    map[x][y].secondaryTexture = currentLoadedTile.secondaryTexture;

    return 1;
}

int isEmptyTexture(texture_t texture)
{
    return texture.letter == EMPTY_TEXTURE_CHAR && texture.number == EMPTY_TEXTURE_NUMBER;
}
