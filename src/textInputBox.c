#include "textInputBox.h"


// init text input box
int initTextInputBox(
    SDL_Renderer * renderer, 
    appContext_t * appContext,
    size_t inputBoxSizeX,
    size_t inputBoxSizeY,
    SDL_Point textInputBoxPosition

){
    //init rect input box
    SDL_Rect inputBoxRect = {
        .x = textInputBoxPosition.x,
        .y = textInputBoxPosition.y,
        .w = inputBoxSizeX,
        .h = inputBoxSizeY
    };
    SDL_Color inputBoxColor = {0, 0, 0, 255};

    // Draw rect of input box
    if( drawThickRect(
        inputBoxRect,
        2,
        inputBoxColor,
        renderer
    )!= 0)
    {
        fprintf(stderr, "drawThickRect error : %s", SDL_GetError());
        return -1;
    }


}

// display value in text input box

int displayTextInputBoxValue(
    SDL_Renderer * renderer,
    appContext_t * appContext,
    size_t inputBoxSizeX,
    size_t inputBoxSizeY,
    SDL_Point textInputBoxPosition
){

    SDL_Rect message_rect = {
        .x = textInputBoxPosition.x,
        .y = textInputBoxPosition.y,
        .w = inputBoxSizeX,
        .h = inputBoxSizeY
    };
    if( addSurfaceToRenderer(
        appContext,
        renderer,
        &message_rect
    )!= 0)
    {
        fprintf(stderr, "addSurfaceToRenderer error : %s", SDL_GetError());
        return -1;
    }

    


    return 0;
}

int addSurfaceToRenderer(
    appContext_t * appContext,
    SDL_Renderer * renderer,
    SDL_Rect * rect
){
    SDL_Surface* surfaceTextInputValue = NULL;
    SDL_Color textColor = { 0, 0, 0, 255 };
    SDL_Texture* textInputValue = NULL;
    TTF_Font * font = TTF_OpenFont( "assets/fonts/font1.ttf", 28 );
    if( font == NULL ){
        fprintf(stderr, "TTF_OpenFont error : %s", TTF_GetError());
        return -1;
    }

    surfaceTextInputValue = TTF_RenderText_Solid( font, appContext->inputText->string, textColor ); 
    if( surfaceTextInputValue == NULL ){
        fprintf(stderr, "TTF_RenderText_Solid error : %s", TTF_GetError());
        return -1;
    }
    
    textInputValue = SDL_CreateTextureFromSurface( renderer, surfaceTextInputValue );
    if( textInputValue == NULL ){
        fprintf(stderr, "SDL_CreateTextureFromSurface error : %s", SDL_GetError());
        return -1;
    }

    SDL_RenderCopy(renderer, textInputValue, NULL, &rect);
    SDL_FreeSurface( surfaceTextInputValue );
    SDL_DestroyTexture( textInputValue );
    TTF_CloseFont( font );
    return 0;
}