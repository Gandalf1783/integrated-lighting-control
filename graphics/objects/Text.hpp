#ifndef UI_TEXT_HPP
#define UI_TEXT_HPP

#include <stdio.h>
#include <stdlib.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include <string.h>

#include "UiObject.hpp"
#include "../Display.hpp"


class Text : public UiObject {
    public:
        Text(SDL_Renderer* renderer);
        Text(SDL_Renderer* renderer, TTF_Font* font);
        ~Text();
        void setText(char* text);
        void render(Display* d);

    private:
        SDL_Renderer* renderer;

        SDL_Texture* sdlTexture;
        SDL_Surface* sdlSurface;
        SDL_Color color;
        TTF_Font* font;
        
        int texW = 0;
        int texH = 0;

        char* textBuf;
        void init(); 
};

#endif