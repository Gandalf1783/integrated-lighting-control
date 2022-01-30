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

void Rectangle::render(char * imageBuffer) {
    u_int64_t location;
    for(int i = x; i < x+width; i++) {
        location =  i * 4 + y * 4096;
        
        *(imageBuffer + location + 0) = r;
        *(imageBuffer + location + 1) = g;
        *(imageBuffer + location + 2) = b;
    }
    for(int i = y; i < y+height; i++) {
        location =  x * 4 + i * 4096;
        
        *(imageBuffer + location + 0) = r;
        *(imageBuffer + location + 1) = g;
        *(imageBuffer + location + 2) = b;
    }
    for(int i = x; i < x+width; i++) {
        location =  i * 4 + (y+height) * 4096;
        
        *(imageBuffer + location + 0) = r;
        *(imageBuffer + location + 1) = g;
        *(imageBuffer + location + 2) = b;
    }
    for(int i = y; i < y+height; i++) {
        location =  (x+width) * 4 + i * 4096;
        
        *(imageBuffer + location + 0) = r;
        *(imageBuffer + location + 1) = g;
        *(imageBuffer + location + 2) = b;
    }
    *(imageBuffer + location + 4) = 0x0;
};

void Rectangle::setDimensions(int width, int height) {
    this->width = width;
    this->height = height;
};

void Rectangle::setPos(int x, int y) {
    this->x = x;
    this->y = y;
};