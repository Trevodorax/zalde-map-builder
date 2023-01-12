#ifndef _UTILS_H_
#define _UTILS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "constants.h"

char * getTileFileName(
    const char letter, 
    const unsigned short number
);

int isLetter(
    char c
);
#endif
