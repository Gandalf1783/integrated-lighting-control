#include "ProgressBar.hpp"

ProgressBar::ProgressBar() {
    x = 0;
    y = 0;
    width = 0; // Breite in px
    height = 0; // Höhe in px,
    margin = 5;
};

void ProgressBar::render(char * framebuffer) {
    // std::cout<<"\n\nProgressBar is rendering:\n";

    u_int64_t location;

    // Diese 2 For-Schleifen malen den Hintergrund
    for(int i = x; i < x+width; i++) {
        for(int j = y; j < y+height; j++) {
            location = i * 4 + // Offset des Pointers für den Pixel
                j * 4096;

            *(framebuffer + location) = 0xFF; // B
            *(framebuffer + location +1) = 0xFF; // G
            *(framebuffer + location +2) = 0xFF; // A
            *(framebuffer + location +3) = 0; // A
        }
    }
    
    progress = progress+2;
    // Prevent over and underflow.
    if(progress<0) progress = 0;
    if(progress>maxProgress)progress = maxProgress;

    float lengthInPx = ((float) progress / (float) maxProgress) * (float)width;
    for(int i = x+margin; i < x+lengthInPx-margin; i++) {
        for(int j = y+margin; j < y+height-margin; j++) {
            location = i * 4 + // Offset des Pointers für den Pixel
                j * 4096;
            
            *(framebuffer + location) = 0xFF; // B
            *(framebuffer + location +1) = 0x00; // G
            *(framebuffer + location +2) = 0x00; // R
            *(framebuffer + location +3) = 0; // A
        }
    }


};

void ProgressBar::setPos(int x, int y) {
    this->x = x;
    this->y = y;
};

void ProgressBar::setDimensions(int width, int height) {
    this->width = width;
    this->height = height;
};