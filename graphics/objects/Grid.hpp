#ifndef GRID_HPP
#define GRID_HPP

#define MAX_GRID_ELEMENTS 300

#include <vector>

#include "UiObject.hpp"

class Texture;
class GridElement;

class Grid : public UiObject {
    public:
        Grid(int xSize, int ySize);
        Grid(SDL_Renderer* renderer);
        ~Grid();
        void setGrid(int numX, int numY, int sizeX, int sizeY); // sizeX and sizeY are one individual items size
        void render(Display* d);
    private:
        Texture* gridFirstTexture;
        SDL_Renderer* renderer;
        SDL_Texture* sdlTexture;
        
        SDL_Color gridLineColor;
        SDL_Color gridBackgColor;


        std::vector<GridElement*> gridElements;

        int xSize, ySize;
        int lineThickness;
};

#include "Texture.hpp"
#include "GridElement.hpp"

#endif