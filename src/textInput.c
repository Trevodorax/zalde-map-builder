#include "textInput.h"



int handleKeydown(
    SDL_Event event,
    appContext_t * appContext,
    SDL_Renderer * renderer
)
{
    switch(event.key.keysym.sym)
    {
        // press enter to save the text input
        case SDLK_RETURN:
            enterValue(appContext, renderer);
            break;
        // press backspace to delete the last character
        case SDLK_BACKSPACE:
            deleteLetter(appContext, renderer);
            break;
        default:
            if(isLetter(event.key.keysym.sym))
            {
                writeLetter(event.key.keysym.sym, appContext, renderer);
            }
            break;
    }
    
    return 0;
}

int writeLetter(
    char letter,
    appContext_t * appContext,
    SDL_Renderer * renderer
) 
{
    appContext->inputText->string = realloc(appContext->inputText->string, appContext->inputText->size + 1);
    if(appContext->inputText->string == NULL)
    {
        fprintf(stderr, "realloc error : %s", SDL_GetError());
        return -1;
    }
    appContext->inputText->string[appContext->inputText->size - 1] = letter;
    appContext->inputText->string[appContext->inputText->size] = '\0';
    appContext->inputText->size++;
    displayTextInputBoxValue(
        renderer,
        appContext
    );
    return 0;

}

int deleteLetter(
    appContext_t * appContext,
    SDL_Renderer * renderer
) 
{
    if(appContext->inputText->size <= 1)
    {
        return 0;
    }

    appContext->inputText->string = realloc(appContext->inputText->string, appContext->inputText->size - 1);
    if(appContext->inputText->string == NULL)
    {
        fprintf(stderr, "realloc error : %s", SDL_GetError());
        return -1;
    }
    appContext->inputText->string[appContext->inputText->size - 2] = '\0';
    appContext->inputText->size--;
    displayTextInputBoxValue(
        renderer,
        appContext
    );

    return 0;
}

int enterValue(
    appContext_t * appContext,
    SDL_Renderer * renderer
)
{
    switch(appContext->inputContext){
        case '0':
            printf("\ntext : %s", appContext->inputText->string);
            return 0;
    }
    
    return 0;
}
