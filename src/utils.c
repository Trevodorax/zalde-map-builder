#include "utils.h"


// get the file name of a tile given a letter and a number
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
    strcat(textureFileName, ".bmp\0");

    return textureFileName;
}
