#include "texturePickerNavigation.h"

// create the navigation buttons
int createNavigation(
    SDL_Renderer * renderer,
    clickListener_t * clickListeners,
    appContext_t * appContext,
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
        (SDL_Rect) {navigationPosition.x, navigationPosition.y, NAVIGATION_BUTTON_SIZE, NAVIGATION_BUTTON_SIZE},
        leftButtonTexture,
        clickListeners,
        'l',
        appContext
    ) != 0 ) return -1;

    if(createNavigationButton(
        renderer,
        (SDL_Rect) {navigationPosition.x + NAVIGATION_BUTTON_SIZE + 10, navigationPosition.y, NAVIGATION_BUTTON_SIZE, NAVIGATION_BUTTON_SIZE},
        rightButtonTexture,
        clickListeners,
        'r',
        appContext
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
    appContext_t * appContext
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
    callbackArgs->appContext = appContext;

    if(createButton(
        BUTTON_TYPE_NAVIGATION,
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
    appContext_t * appContext = callbackArgs->appContext;

    // erase the previous texture picker
    if(deleteButtonsByType(
        BUTTON_TYPE_TEXTURE_PICKER,
        renderer,
        clickListeners
    ) != 0) {
        fprintf(stderr, "error deleting tile picker");
        return;
    };

    // set the new category letter
    setCategoryLetter(
        direction,
        appContext
    );

    // create the new texture picker
    if(
        createTexturePickerCategory(
            renderer,
            appContext,
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
    appContext_t * appContext
)
{
    if(direction == 'l')
    {
        if(appContext->texturePickerLetter == 'A')
        {
            appContext->texturePickerLetter = 'Z';
        }
        else
        {
            appContext->texturePickerLetter = appContext->texturePickerLetter - 1;
        }
    }
    else if(direction == 'r')
    {
        if(appContext->texturePickerLetter == 'Z')
        {
            appContext->texturePickerLetter = 'A';
        }
        else
        {
            appContext->texturePickerLetter = appContext->texturePickerLetter + 1;
        }
    }
    else
    {
        fprintf(stderr, "invalid direction");
        return;
    }

    return;
}
