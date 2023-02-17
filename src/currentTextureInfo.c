#include "../include/currentTextureInfo.h"

int createCurrentTextureInfo(SDL_Renderer * renderer)
{
    if(drawThickRect(
        (SDL_Rect) {CURRENT_TEXTURE_INFO_POS_X, CURRENT_TEXTURE_INFO_POS_Y, CURRENT_TEXTURE_INFO_SIZE, CURRENT_TEXTURE_INFO_SIZE},
        5,
        (SDL_Color) {0, 0, 0, 255},
        renderer
    ) != 0)
    {
        fprintf(stderr, "drawThickRect error");
    }   

    return 0;
}

int updateCurrentTextureInfo(
    SDL_Renderer * renderer,
    char letter,
    unsigned short number
)
{
    SDL_Rect currentTextureInfoRect =  {CURRENT_TEXTURE_INFO_POS_X, CURRENT_TEXTURE_INFO_POS_Y, CURRENT_TEXTURE_INFO_SIZE, CURRENT_TEXTURE_INFO_SIZE};

    // erase previous texture
    if(drawFillRect(
        currentTextureInfoRect,
        (SDL_Color) {255, 255, 255, 255},
        renderer
    ) != 0)
    {
        fprintf(stderr, "drawFillRect error");
        return -1;
    }

    // put the texture on it
    SDL_Texture * tileTexture = getImageTexture(
        renderer, 
        getTileFileName(
            letter,
            number
        )
    );
    if(!tileTexture)
    {
        return -1;
    }

    if(SDL_RenderCopy(renderer, tileTexture, NULL, &currentTextureInfoRect) != 0)
    {
        fprintf(stderr, "SDL_RenderCopy error: %s", SDL_GetError());
        return -1;
    }

    return 0;
}
