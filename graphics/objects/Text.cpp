#include "Text.hpp"

Text::Text(SDL_Renderer* renderer) {
    this->renderer = renderer;
    if(this->renderer == nullptr) {
        printf("[UIOBJECT] [TEXT] Submitted renderer is NULL.\n");
        exit(18);
    }

    this->font = TTF_OpenFont("/root/dmx_engine/arial.ttf", 20);
    if(this->font == nullptr) {
        printf("[UIOBJECT] [TEXT] Could not load font.\n");
        exit(18);
    }
    printf("[Text] Using font 0x%x\n", this->font);

    this->textBuf = (char*) malloc(512);
    sprintf(this->textBuf, "Dies ist ein Test! (0x%x)", this);
    init();
};

Text::Text(SDL_Renderer* renderer, TTF_Font* font) {
    this->renderer = renderer;
    if(this->renderer == nullptr) {
        printf("[UIOBJECT] [TEXT] Submitted renderer is NULL.\n");
    }

    this->font = font;
    if(this->font == nullptr) {
        printf("[UIOBJECT] [TEXT] Submitted font is NULL.\n");
    }

    this->textBuf = (char*) malloc(512);
    sprintf(this->textBuf, "Dies ist ein Test! (0x%x)", this);
    init();
};

Text::~Text() {
    this->font = nullptr;

    if(this->textBuf == nullptr)
        return;
    
    free(this->textBuf);
    this->textBuf = nullptr;
};

void Text::setText(char* text) {
    strcpy(this->textBuf,text);
}

void Text::init() {
    color = { 255, 255, 255 };
};

void Text::render(Display* d) {
    if(this->font == nullptr || this->renderer == nullptr)
        return;
    
    sdlSurface = TTF_RenderText_Solid(font, textBuf, color);
    if(sdlSurface == nullptr)
        return;
    
    sdlTexture = SDL_CreateTextureFromSurface(this->renderer, sdlSurface);
    if(sdlTexture == nullptr)
        return;


    SDL_QueryTexture(sdlTexture, NULL, NULL, &texW, &texH);
    this->drawingRect = { this->drawingRect.x, this->drawingRect.y, texW, texH };
    SDL_RenderCopy(renderer, sdlTexture, NULL, &(this->drawingRect));

    SDL_DestroyTexture(sdlTexture);
    SDL_FreeSurface(sdlSurface);
};