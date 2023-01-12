#include "textInput.h"



int handlelKeydown(
    SDL_Event event,
    sizedString_t * text,
    char inputContext
)
{
    switch(event.key.keysym.sym)
    {
        // press enter to save the text input
        case SDLK_RETURN:
            enterValue(text, inputContext);
            return 0;
        // press backspace to delete the last character
        case SDLK_BACKSPACE:
            deleteLetter(text);
            return 0;
    }
    if(isLetter(event.key.keysym.sym))
    {
        writeLetter(event.key.keysym.sym, text);
    }
}

int writeLetter(
    char letter,
    sizedString_t * text
) 
{
    text->string = realloc(text->string, text->size + 1);
    if(text->string == NULL)
    {
        fprintf(stderr, "realloc error : %s", SDL_GetError());
        return -1;
    }
    text->string[text->size - 1] = letter;
    text->string[text->size] = '\0';
    text->size++;
    return 0;

}

int deleteLetter(
    sizedString_t * text
) 
{
    if(text->size > 1)
    {
        text->string = realloc(text->string, text->size - 1);
        if(text->string == NULL)
        {
            fprintf(stderr, "realloc error : %s", SDL_GetError());
            return -1;
        }
        text->string[text->size - 2] = '\0';
        text->size--;
    }
    return 0;
}

int enterValue(
    sizedString_t * string,
    char inputContext
)
{
    switch(inputContext){
        case '0':
            return 0;
    }
}
