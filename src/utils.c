#include "utils.h"

char * getTileFileName(
    const char letter, 
    const unsigned short number
) 
{
    // variables that compose the texture file name
    char textureFileLetter[2] = "?\0";
    char textureFileNumberString[3];

    // concatenatiuon of all previous variables
    char * textureFileName = malloc(30 * sizeof(char));
    textureFileName[0] = '\0';

    // use the values given in params
    textureFileLetter[0] = letter;

    sprintf(textureFileNumberString, "%hu", number);

    strcat(textureFileName, "assets/tileset/\0");
    strcat(textureFileName, textureFileLetter);
    strcat(textureFileName, textureFileNumberString);
    strcat(textureFileName, ".png\0");


    // probably won't work, have to make textureFileName a pointer
    return textureFileName;
}
