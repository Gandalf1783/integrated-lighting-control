#include "GridElement.hpp"

GridElement::GridElement() {

};
GridElement::GridElement(SDL_Renderer* renderer, int gridIndex) {
    this->renderer = renderer;
    this->gridIndex = gridIndex;

    this->primTexture = new Texture(renderer);
    this->flashTexture = new Texture(renderer);
    this->foregText = new Text(renderer);

    if(gridIndex > 0) {
        this->primTexture->loadTexture("/root/dmx_engine/assets/border_tile_blue_0000ff.bmp");
        this->flashTexture->loadTexture("/root/dmx_engine/assets/border_tile_white_ffffff.bmp");
    } else {
        this->primTexture->loadTexture("/root/dmx_engine/assets/grid_first_tile.bmp");
    }

    

    this->numberBuffer = (char*) malloc(10);

    sprintf(this->numberBuffer, "%d", this->gridIndex);

    this->foregText->setText(this->numberBuffer);
    this->flashing = (gridIndex % 2 == 1 ? SLOW : FAST);
    this->backgTexture = this->primTexture;
};


GridElement::~GridElement() {
    delete this->primTexture;
    delete this->foregText;
    this->backgTexture = nullptr;
    free(this->numberBuffer);
};

void GridElement::setPos(int x, int y) {
    this->drawingRect.x = x;
    this->drawingRect.y = y;

    if(gridIndex > 0) {
        this->flashTexture->setPos(this->drawingRect.x, this->drawingRect.y);
    }

    this->primTexture->setPos(this->drawingRect.x, this->drawingRect.y);
    this->foregText->setPos(this->drawingRect.x+5, this->drawingRect.y+2);
}

void GridElement::setSize(int width, int height) {
    this->drawingRect.w = width;
    this->drawingRect.h = height;

    if(gridIndex > 0) {
        this->flashTexture->setSize(this->drawingRect.w, this->drawingRect.h);
    }
    this->primTexture->setSize(this->drawingRect.w, this->drawingRect.h);
}

void GridElement::render(Display* d) {
    if(this->gridIndex > 0) {
        if(this->flashing == SLOW && flashStateSlow) {
            this->backgTexture = this->flashTexture;
        } else if(this->flashing == FAST && flashStateFast) {
            this->backgTexture = this->flashTexture;
        } else if(this->flashing == NONE) {
            this->backgTexture = this->primTexture;
        } else {
            this->backgTexture = this->primTexture;
        }
    }
    this->backgTexture->render(d);
    this->foregText->render(d);
};