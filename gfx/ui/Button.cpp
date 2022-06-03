#include "Button.hpp"

Button::Button() {

};

void Button::render(Framebuffer fb) {
    for(int i = x; i < x+100; i++) {
        for(int j = y; j < y+100; j++) {
            char c = (this->isPressed ? colorPressed : colorUnpressed);
            fb.setPixel(i,j,c,c,c);
        }
    }
};

void Button::mouseMoveEvent(int x, int y) {

};

void Button::freeMemory() {

};

void Button::mouseReleasedEvent(int x, int y) {
    printf("BUTTON WAS CLICKED!\n");
}