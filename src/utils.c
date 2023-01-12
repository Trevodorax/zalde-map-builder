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

    strcat(textureFileName, PATH_TO_TILESET);
    strcat(textureFileName, textureFileLetter);
    strcat(textureFileName, textureFileNumberString);
    strcat(textureFileName, ".bmp\0");

    return textureFileName;
}

// check if a character is a letter
int isLetter(
    char c
)
{
    if (c >= 'a' && c <= 'z')
        return 1;
    if (c >= 'A' && c <= 'Z')
        return 1;
    return 0;
}
