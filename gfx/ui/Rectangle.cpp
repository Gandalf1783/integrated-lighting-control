#include "Rectangle.hpp"


Rectangle::Rectangle() {
    x = 100;
    y = 100;
    width = 100;
    height = 100;
    r = 210;
    g = 140;
    b = 10;
};

void Rectangle::render(Framebuffer fb) {
    for(int i = x; i < x+width; i++) {
        fb.setPixel(i,y,r,g,b);
    }
    for(int i = y; i < y+height; i++) {
        fb.setPixel(x,i,r,g,b);
    }
    for(int i = x; i < x+width; i++) {
        fb.setPixel(i,y+height,r,g,b);
    }
    for(int i = y; i < y+height; i++) {
        fb.setPixel(x+width,i,r,g,b);
        
    }
};

void Rectangle::setDimensions(int width, int height) {
    this->width = width;
    this->height = height;
};

void Rectangle::setPos(int x, int y) {
    this->x = x;
    this->y = y;
};

void Rectangle::mouseMoveEvent(int x, int y) {

}

void Rectangle::freeMemory() {

};


void Rectangle::mouseReleasedEvent(int x, int y) {

}