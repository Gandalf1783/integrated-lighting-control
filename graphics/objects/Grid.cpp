#include "Grid.hpp"

Grid::Grid(int xSize, int ySize) {
    this->xSize = xSize;
    this->ySize = ySize;
    this->lineThickness = 2;
};

Grid::Grid(SDL_Renderer* renderer) {
    this->renderer = renderer;

    this->gridBackgColor.r = 0x10;
    this->gridBackgColor.g = 0x10;
    this->gridBackgColor.b = 0x10;
    this->gridBackgColor.a = 0xFF;

    this->gridLineColor.r = 0xb8;
    this->gridLineColor.g = 0x7d;
    this->gridLineColor.b = 0x00;
    this->gridLineColor.a = 0xFF;

    this->drawingRect.x = 200;
    this->drawingRect.y = 200;
    this->drawingRect.w = 760;
    this->drawingRect.h = 760;

    this->xSize = 10;
    this->ySize = 10;
    this->lineThickness = 2;
    
    this->gridFirstTexture = new Texture(this->renderer);
    this->gridFirstTexture->loadTexture("/root/dmx_engine/assets/grid_first_tile.bmp");
    this->gridFirstTexture->setSize(76,76);

    for(int i = 0; i < 5; i++) {
        this->gridElements.push_back(new GridElement(renderer, i));
    }
};

Grid::~Grid() {
    delete this->gridFirstTexture;
};

void Grid::render(Display* d) {
    //this->gridBackgColor.r = (this->gridBackgColor.r) +1;
    SDL_SetRenderDrawColor(this->renderer, this->gridBackgColor.r,this->gridBackgColor.g,this->gridBackgColor.b,this->gridBackgColor.a);
    SDL_RenderFillRect(this->renderer, &(this->drawingRect));
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);

    SDL_SetRenderDrawColor(this->renderer, this->gridLineColor.r,this->gridLineColor.g,this->gridLineColor.b,this->gridLineColor.a);
    int sizeSingleBoxX = (this->drawingRect.w / this->xSize);
    int sizeSingleBoxY = (this->drawingRect.h / this->ySize);

    //Vertical Lines (Col)
    for(int i = 1; i < this->xSize; i++) {
        int xOffset = sizeSingleBoxX*i;

        SDL_Rect lineRect;
        lineRect.x = this->drawingRect.x + xOffset;
        lineRect.y = this->drawingRect.y;
        lineRect.w = this->lineThickness;
        lineRect.h = this->drawingRect.h;

        //this->targRect.x+xOffset,this->targRect.y, this->targRect.x+xOffset, this->targRect.y+this->targRect.h-1
        
        SDL_RenderFillRect(this->renderer, &lineRect);
    }

    for(int i = 1; i < this->ySize; i++) {
        int yOffset = sizeSingleBoxY*i;

        SDL_Rect lineRect;
        lineRect.x = this->drawingRect.x;
        lineRect.y = this->drawingRect.y + yOffset;
        lineRect.h = this->lineThickness;
        lineRect.w = this->drawingRect.w;

        //this->targRect.x+xOffset,this->targRect.y, this->targRect.x+xOffset, this->targRect.y+this->targRect.h-1

        SDL_RenderFillRect(this->renderer, &lineRect);
    }
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);

    for(int i = 0; i < this->gridElements.size(); i++) {
        this->gridElements.at(i)->setPos(this->drawingRect.x+(i*sizeSingleBoxX),this->drawingRect.y);
        this->gridElements.at(i)->setSize(sizeSingleBoxX, sizeSingleBoxY);

        this->gridElements.at(i)->render(d);
    }

};