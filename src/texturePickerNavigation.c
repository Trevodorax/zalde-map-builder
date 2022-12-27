#include "texturePickerNavigation.h"

// create the navigation buttons
int createNavigation(
    SDL_Renderer * renderer,
    clickListener_t * clickListeners,
    char * texturePickerCategoryLetter,
    SDL_Point navigationPosition
)
{
    SDL_Texture * leftButtonTexture;
    SDL_Texture * rightButtonTexture;

    leftButtonTexture = getImageTexture(renderer, "assets/buttons/left.bmp");
    rightButtonTexture = getImageTexture(renderer, "assets/buttons/right.bmp");

    if(!leftButtonTexture || !rightButtonTexture)
    {
        return -1;
    }

    if(createNavigationButton(
        renderer,
        (SDL_Rect) {navigationPosition.x, navigationPosition.y, 50, 50},
        leftButtonTexture,
        clickListeners,
        'l',
        texturePickerCategoryLetter
    ) != 0 ) return -1;

    if(createNavigationButton(
        renderer,
        (SDL_Rect) {navigationPosition.x + 60, navigationPosition.y, 50, 50},
        rightButtonTexture,
        clickListeners,
        'r',
        texturePickerCategoryLetter
    ) != 0 ) return -1;

    return 0;
}


// create a navigation button given a direction
int createNavigationButton(
    SDL_Renderer * renderer,
    SDL_Rect buttonRect,
    SDL_Texture * buttonTexture,
    clickListener_t * clickListeners,
    char navDirection,
    char * texturePickerCategoryLetter
)
{
    setTexturePickerCategoryArgs_t * callbackArgs = malloc(sizeof(setTexturePickerCategoryArgs_t));
    if(callbackArgs == NULL)
    {
        fprintf(stderr, "malloc error");
        return -1;
    }
    callbackArgs->direction = navDirection;
    callbackArgs->renderer = renderer;
    callbackArgs->clickListeners = clickListeners;
    callbackArgs->texturePickerCategoryLetter = texturePickerCategoryLetter;

    if(createButton(
        'n',
        buttonRect,
        setTexturePickerCategory,
        callbackArgs,
        buttonTexture,
        clickListeners,
        renderer
    ) != 0) return -1;

    SDL_DestroyTexture(buttonTexture);

    return 0;
}


// set the global value of the current tile category
void setTexturePickerCategory(
    void * args
)
{
    // get the args in the right struct
    setTexturePickerCategoryArgs_t * callbackArgs = (setTexturePickerCategoryArgs_t *) args;

    // get all the required parameters
    char direction = callbackArgs->direction;
    SDL_Renderer * renderer = callbackArgs->renderer;
    clickListener_t * clickListeners = callbackArgs->clickListeners;
    char * texturePickerCategoryLetter = callbackArgs->texturePickerCategoryLetter;

    // erase the previous texture picker
    if(deleteButtonsByType(
        't',
        renderer,
        clickListeners
    ) != 0) {
        fprintf(stderr, "error deleting tile picker");
        return;
    };

    // set the new category letter
    setCategoryLetter(
        direction,
        texturePickerCategoryLetter
    );

    // create the new texture picker
    if(
        createTexturePickerCategory(
            renderer,
            *texturePickerCategoryLetter,
            clickListeners,
            TEXTURE_PICKER_SIZE,
            (SDL_Point) {TILE_SECTION_POS_X, TILE_SECTION_POS_Y + 60}
        ) != 0
    ) {
        fprintf(stderr, "error creating tile picker");
        return;
    }

    return;
}


// sets the category letter to the next or previous one
void setCategoryLetter(
    char direction,
    char * categoryLetter
)
{
    if(direction == 'l')
    {
        if(*categoryLetter == 'A')
        {
            *categoryLetter = 'Z';
        }
        else
        {
            *categoryLetter = *categoryLetter - 1;
        }
    }
    else if(direction == 'r')
    {
        if(*categoryLetter == 'Z')
        {
            *categoryLetter = 'A';
        }
        else
        {
            *categoryLetter = *categoryLetter + 1;
        }
    }
    else
    {
        fprintf(stderr, "invalid direction");
        return;
    }

    return;
}
