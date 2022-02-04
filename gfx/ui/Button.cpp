#include "Button.hpp"

Button::Button() {

};

void Button::render(char * imageBuffer, int lineLength) {
    u_int64_t location;

    for(int i = x; i < x+100; i++) {
        for(int j = y; j < y+100; j++) {

            location = (i*4) + (j * 4096);
            char c = (this->isPressed ? colorPressed : colorUnpressed);
            *(imageBuffer + location) = c; //B
            *(imageBuffer + location +1) = c; //G
            *(imageBuffer + location +2) = c; //R
            *(imageBuffer + location +3) = 0x0; //A
        }
    }
};

void Button::mouseMoveEvent(int x, int y) {

};

void Button::freeMemory() {

};