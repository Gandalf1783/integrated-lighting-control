#ifndef GRID_ELEMENT_HPP
#define GRID_ELEMENT_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "UiObject.hpp"

class Texture;
class Text;


class GridElement : public UiObject {
    public:
        GridElement();
        GridElement(SDL_Renderer* renderer, int gridIndex);
        ~GridElement();

        void setPos(int x, int y);
        void setSize(int width, int height);
        
        void render(Display* d);

    private:
        SDL_Renderer* renderer;
        Texture* backgTexture;
        Texture* primTexture;
        Texture* flashTexture;
        Text* foregText;
        FlashState flashing;
        int gridIndex;
        char* numberBuffer;
};

#include "Texture.hpp"
#include "Text.hpp"

#endif