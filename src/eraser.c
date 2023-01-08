#include "eraser.h"

int createEraserButton()
{
    // TODO create a button at the right coordinates
    return 0;
}

void startErasing(void * voidArgs)
{ 
    startErasingArgs_t * args = (startErasingArgs_t *) voidArgs;

    args->appContext->isErasing = 1;
    // TODO set this to false whenn texture picker touched
}
