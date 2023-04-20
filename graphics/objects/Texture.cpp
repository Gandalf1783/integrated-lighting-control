#include "Texture.hpp"


SDL_Texture *IMG_LoadTexture(SDL_Renderer *renderer, const char *file)
{
    printf("[TEXTURE] : Loading %s\n", file);

    SDL_Texture *texture = NULL;
    SDL_Surface *surface = IMG_Load(file);
    
    if (surface) {
        texture = SDL_CreateTextureFromSurface(renderer, surface);
        

        #define DEBUG
        #ifdef DEBUG
        printf("[TEXTURE] Loaded into 0x%x\n", texture);
        printf("[TEXTURE] Possible Error would be displayed here: %s\n", SDL_GetError());
        printf("[TEXTURE] Renderer: 0x%x\n", renderer);
        #endif


        SDL_FreeSurface(surface);
    }

    return texture;
}

Texture::Texture(SDL_Renderer* renderer) {
    this->renderer = renderer;
};

Texture::~Texture() {
    printf("[TEXTURE] (0x%x) : Unloading texture 0x%x.", this, this->texture);
    SDL_DestroyTexture(this->texture);
};

void Texture::render(Display* d) {
    if(this->posType == CENTER) {
        SDL_Rect* disDimensions = d->getDisplayDimensions();
        SDL_Rect newPos;
        double widthHalf = drawingRect.w/2;
        double heightHalf = drawingRect.h/2;

        newPos.x = ((disDimensions->w/2)) - (widthHalf);
        newPos.y = ((disDimensions->h/2)) - (heightHalf);
        newPos.w = drawingRect.w;
        newPos.h = drawingRect.h;
        //printf("Render at %d|%d with size of %d|%d\n", newPos.x, newPos.y, newPos.w, newPos.h);
        SDL_RenderCopy(this->renderer, this->texture, NULL, &newPos);

        return;
    }
    SDL_RenderCopy(this->renderer, this->texture, NULL, &(this->drawingRect));
};

void Texture::setTexture(SDL_Texture* texture) {
    this->texture = texture;
};

void Texture::loadTexture(char* path) {
    //The final texture
    SDL_Texture* newTexture = NULL;

    //Load image at specified path
    newTexture = IMG_LoadTexture(this->renderer, path);

    SDL_QueryTexture(newTexture, nullptr, nullptr, &origWidth, &origHeight);

    printf("NewTexture: 0x%x\n", newTexture);
    this->texture = newTexture;
};