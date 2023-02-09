#include "saveMap.h"


int saveMapName(
    sizedString_t * mapName
)
{
    char * mapNameWithExt = malloc(mapName->size + 11);
    char extention[7] = ".zalde";

    if(mapNameWithExt == NULL)
    {
        fprintf(stderr, "\nmalloc error");
        return -1;
    }
    mapNameWithExt[0] = '\0';
    
    strcat(mapNameWithExt, "maps/");
    strcat(mapNameWithExt, mapName->string);
    strcat(mapNameWithExt, extention);

    FILE * mapNameFile = fopen(mapNameWithExt, "w");
    if(mapNameFile == NULL)
    {
        fprintf(stderr, "\nError opening mapName.txt");
        return -1;
    }

    free(mapNameWithExt);
    fclose(mapNameFile);

    return 0;
}