#include "Mouse.hpp"


Mouse::Mouse() {
    this->x = 1024/2;
    this->y = 768/2;
};

void Mouse::render(char * imageBuffer, int lineLength) {
    u_int64_t location;
    //printf("this: 0x%x (render)\n", this);
    for(int i = this->x; i < this->x+4; i++) {
        for(int j = this->y; j < this->y+4; j++) {
            location = (i*4) + j * lineLength;
            //printf("x: %u | y: %u\n", this->x,this->y);
            *(imageBuffer + location) = 0xFF;
            *(imageBuffer + location +1) = 0xFF;
            *(imageBuffer + location +2) = 0xFF;
            *(imageBuffer + location +3) = 0x0;
        };
    };
};

void Mouse::setPos(int x, int y) {
    this->x = x;
    this->y = y;
};

void Mouse::setDelta(int dX, int dY) {
    this->x = this->x+dX;
    this->y = this->y-dY;
}

void Mouse::mouseMoveEvent(int x, int y) {

};

void Mouse::freeMemory() {

};