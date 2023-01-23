#include "textInputBox.h"


// init text input box
int initTextInputBox(
    SDL_Renderer * renderer, 
    appContext_t * appContext

)
{
    // init rect input box
    SDL_Rect inputBoxRect = {
        .x = INPUT_BOX_POS_X,
        .y = INPUT_BOX_POS_Y,
        .w = INPUT_BOX_MAX_WIDTH,
        .h = INPUT_BOX_HEIGHT
    };
    SDL_Color inputBoxColor = {0, 0, 0, 255};

    // draw rect of input box
    if(drawThickRect(
        inputBoxRect,
        2,
        inputBoxColor,
        renderer
    )!= 0)
    {
        fprintf(stderr, "\ndrawThickRect error");
        return -1;
    }

    // display text input box
    
    if(appContext->inputText->size > 1){
        
        if(displayTextInputBoxValue(
            renderer,
            appContext
        )!= 0)
        {
            fprintf(stderr, "\ndisplayTextInputBoxValue error");
            return -1;
        }
    }

    return 0;
}

// display value in text input box

int displayTextInputBoxValue(
    SDL_Renderer * renderer,
    appContext_t * appContext
)
{

    SDL_Rect messageRect = {
        .x = INPUT_BOX_POS_X + 2,
        .y = INPUT_BOX_POS_Y + 2,
        .w = LETTER_SIZE * appContext->inputText->size,
        .h = LETTER_SIZE + 2
    };

    if(renderInputBox(
        appContext,
        renderer,
        &messageRect
    ) != 0)
    {
        fprintf(stderr, "\nrenderInputBox error");
        return -1;
    }

    return 0;
}

int renderInputBox(
    appContext_t * appContext,
    SDL_Renderer * renderer,
    SDL_Rect * rect
)
{
    SDL_Surface * surfaceTextInputValue = NULL;
    SDL_Color textColor = { 0, 0, 0, 255 };
    SDL_Texture * textInputValue = NULL;
    TTF_Font * font = TTF_OpenFont("assets/fonts/font1.ttf", 28);

    if(font == NULL){
        fprintf(stderr, "\nTTF_OpenFont error : %s", TTF_GetError());
        return -1;
    }

    surfaceTextInputValue = TTF_RenderText_Solid(font, appContext->inputText->string, textColor); 
    if(surfaceTextInputValue == NULL){
        fprintf(stderr, "\nTTF_RenderText_Solid error : %s", TTF_GetError());
        return -1;
    }
    
    textInputValue = SDL_CreateTextureFromSurface( renderer, surfaceTextInputValue );
    if(textInputValue == NULL){
        fprintf(stderr, "\nSDL_CreateTextureFromSurface error : %s", SDL_GetError());
        return -1;
    }

    if(eraseInputBox(renderer) != 0) {
        fprintf(stderr, "\neraseInputBox error");
        return -1;
    }

    SDL_RenderCopy(renderer, textInputValue, NULL, rect);
    SDL_FreeSurface(surfaceTextInputValue);
    SDL_DestroyTexture(textInputValue);
    TTF_CloseFont(font);

    return 0;
}


int eraseInputBox(
    SDL_Renderer * renderer
)
{
    SDL_Rect inputBoxRect = {
        .x = INPUT_BOX_POS_X,
        .y = INPUT_BOX_POS_Y,
        .w = INPUT_BOX_MAX_WIDTH,
        .h = INPUT_BOX_HEIGHT
    };
    SDL_Color inputBoxColor = {255, 255, 255, 255};
    // erase last text
    SDL_SetRenderDrawColor(renderer, inputBoxColor.r, inputBoxColor.g, inputBoxColor.b, inputBoxColor.a);
    
    if(SDL_RenderFillRect(renderer, &inputBoxRect) != 0)
    {
        fprintf(stderr, "\nSDL_RenderFillRect error : %s", SDL_GetError());
        return -1;
    }

    return 0;
}
