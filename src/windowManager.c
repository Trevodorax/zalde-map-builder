#include "windowManager.h"

#define WINDOW_SIZE_X 1280
#define WINDOW_SIZE_Y 660

#define TILE_SECTION_POS_X 10
#define TILE_SECTION_POS_Y 10
#define TILE_SIZE 64

int initMainWindow(windowAndRenderer_t * mainWindow) 
{
    if(initWindowAndRenderer(mainWindow, "Map builder", WINDOW_SIZE_X, WINDOW_SIZE_Y) != 0) {
        return -1;
    }

    SDL_Color backgroundColor = {255, 255, 255, 255};

    if(setBackgroundColor(mainWindow->renderer, backgroundColor) != 0) {
        return -1;
    }

    SDL_RenderPresent(mainWindow->renderer);

    SDL_Delay(5);
    return 0;
}



int createTexturePicker(
    windowAndRenderer_t * mainWindow, 
    clickListener_t ** clickListeners, 
    size_t * clickListenersSize,
    char textureFileLetter
) 
{

        
        if(createTexturePickerCategory(
            mainWindow->renderer, 
            textureFileLetter, 
            clickListeners, 
            clickListenersSize
        ) != 0) {
            return -1;
        }


    return 0;
}

int createTexturePickerCategory(
    SDL_Renderer * renderer, 
    const char categoryLetter,
    clickListener_t ** clickListeners,
    size_t * clickListenersSize
)
{
    int i, j;
    unsigned short textureFileNumber = 1;
    char * tileFileName;
    SDL_Texture * tileTexture;
    SDL_Texture * buttonTextureLeft;
    SDL_Texture * buttonTextureRight;

    buttonTextureRight = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, 
                                SDL_TEXTUREACCESS_TARGET, 10, 10);
    if(buttonTextureRight == NULL)
    {
        fprintf(stderr, "Erreur SDL_CreateTexture : %s", SDL_GetError());
        return -1;
    }

    //We create 2 button to navigate

    SDL_Rect buttonRectCategorieRight = {TILE_SECTION_POS_X+11*TILE_SIZE,TILE_SECTION_POS_Y,TILE_SIZE,TILE_SIZE};
    SDL_Rect buttonRectCategorieLeft = {TILE_SECTION_POS_X+10*TILE_SIZE,TILE_SECTION_POS_Y,TILE_SIZE,TILE_SIZE};

    buttonTextureLeft = getImageTexture(renderer, "assets/buttons/left.bmp");
    buttonTextureRight = getImageTexture(renderer, "assets/buttons/right.bmp");

    navDirectionsArgs_t *navArgsRight = malloc(sizeof(navDirectionsArgs_t));
    if(navArgsRight == NULL)
    {
        fprintf(stderr, "malloc error");
        return -1;
    }
    navArgsRight->navDirection = *"r";
    createButton(
        buttonRectCategorieRight,
        setCategorie,
        'f',
        navArgsRight,
        buttonTextureRight,
        clickListeners,
        clickListenersSize,
        renderer
    );

    navDirectionsArgs_t *navArgsLeft = malloc(sizeof(navDirectionsArgs_t));
    if(navArgsLeft == NULL)
    {
        fprintf(stderr, "malloc error");
        return -1;
    }
    navArgsLeft->navDirection = *"l";

    createButton(
        buttonRectCategorieLeft,
        setCategorie,
        'f',
        navArgsLeft,
        buttonTextureLeft,
        clickListeners,
        clickListenersSize,
        renderer
    );

    for(i = 0; i < 10; i++)
    {
        for(j = 0; j < 10; j++)
        {
            SDL_Delay(3);
            setCurrentTileArgs_t * tileInfos = malloc(sizeof(setCurrentTileArgs_t));
            if(tileInfos == NULL)
            {
                fprintf(stderr, "malloc error");
                return -1;
            }

            tileInfos->tileLetter = categoryLetter;
            tileInfos->tileNumber = textureFileNumber;

            tileFileName = getTileFileName(categoryLetter, textureFileNumber);

            // start using the file name here
            tileTexture = getImageTexture(renderer, tileFileName);
            if(!tileTexture)
            {
                return 0;
            }

            SDL_Rect buttonRectTile = {TILE_SECTION_POS_X + (j * TILE_SIZE), TILE_SECTION_POS_X + (i * TILE_SIZE), TILE_SIZE, TILE_SIZE};
            createButton(
                buttonRectTile,
                setCurrentTile,
                'p',
                tileInfos,
                tileTexture,
                clickListeners,
                clickListenersSize,
                renderer
            );

            // stop using the file name here
            SDL_DestroyTexture(tileTexture);
            free(tileFileName);

            textureFileNumber++;
        }
    }

    return 0;
}

void setCurrentTile(
    void * tileInfos
)
{
    setCurrentTileArgs_t * tileInfosStruct = (setCurrentTileArgs_t *) tileInfos;

    extern char currentTileLetter;
    currentTileLetter = tileInfosStruct->tileLetter;
    extern unsigned short currentTileNumber;
    currentTileNumber = tileInfosStruct->tileNumber;
    
    return;
}

void setCategorie(
    navDirectionsArgs_t * navArgs
)
{
    createTexturePicker(navArgs->mainWindow, navArgs->clickListeners, navArgs->clickListenersSize, navArgs->textureCategorieLetter);
    extern char textureFileLetter;
    textureFileLetter = navArgs->textureCategorieLetter;
}