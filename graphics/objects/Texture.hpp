#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include <stdio.h>
#include <stdlib.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "UiObject.hpp"
#include "../Display.hpp"

class Texture : public UiObject {
    public:
        Texture(SDL_Renderer* renderer);
        ~Texture();
        void render(Display* d);
        void setTexture(SDL_Texture* texture);
        void loadTexture(char* path); // Will unload prev. textures
    private:
        SDL_Texture* texture;
        SDL_Renderer* renderer;
        SDL_Rect origRect;
        SDL_Rect targRect;
        int origWidth, origHeight;

};

#endif