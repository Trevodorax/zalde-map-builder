#include "loadMap.h"

int loadMap(mapTile_t map[MAP_SIZE][MAP_SIZE], char * mapName)
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
                currentLoadedTile
            );

            fgetc(mapFile); // skip the semicolon
        }
        fgetc(mapFile); // skip the newline
    }

    fclose(mapFile);
    return 0;
}

int handleLoadedTile(
    mapTile_t map[MAP_SIZE][MAP_SIZE],
    size_t x,
    size_t y,
    mapTile_t currentLoadedTile
)
{
    if(currentLoadedTile.isLinkedMap)
    {
        printf("\nmap[%zu][%zu] leads to a linked map.", x, y);
    }

    if(isEmptyTexture(currentLoadedTile.primaryTexture))
    {
        return 1;
    }
    
    printf("\nReplace primary texture in map[%zu][%zu] with %c%hu", x, y, currentLoadedTile.primaryTexture.letter, currentLoadedTile.primaryTexture.number);

    if(isEmptyTexture(currentLoadedTile.secondaryTexture))
    {
        return 1;
    }
    
    printf("\nReplace secondary texture in map[%zu][%zu] with %c%hu", x, y, currentLoadedTile.secondaryTexture.letter, currentLoadedTile.secondaryTexture.number);

    return 1;
}

isEmptyTexture(texture_t texture)
{
    return texture.letter == EMPTY_TEXTURE_CHAR && texture.number == EMPTY_TEXTURE_NUMBER;
}
