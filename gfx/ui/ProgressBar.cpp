#include "ProgressBar.hpp"

ProgressBar::ProgressBar() {
    x = 0;
    y = 0;
    width = 0; // Breite in px
    height = 0; // Höhe in px,
    margin = 5;
};

void ProgressBar::render(char * imageBuffer, int lineLength) {
    // std::cout<<"\n\nProgressBar is rendering:\n";
    progress++;
    u_int64_t location;

    // Diese 2 For-Schleifen malen den Hintergrund
    for(int i = x; i < x+width; i++) {
        for(int j = y; j < y+height; j++) {
            location = i * 4 + // Offset des Pointers für den Pixel
                j * lineLength;

            *(imageBuffer + location) = 0xFF; // B
            *(imageBuffer + location +1) = 0xFF; // G
            *(imageBuffer + location +2) = 0xFF; // A
            *(imageBuffer + location +3) = 0; // A
        }
    }
    
    // Prevent over and underflow.
    if(progress<0) progress = 0;
    if(progress>maxProgress)progress = maxProgress;

    float lengthInPx = ((float) progress / (float) maxProgress) * (float)width; // calculate percentage and then upscale to pixels
    for(int i = x+margin; i < x+lengthInPx-margin; i++) {
        for(int j = y+margin; j < y+height-margin; j++) {
            location = i * 4 + // Offset des Pointers für den Pixel
                j * lineLength;
            
            *(imageBuffer + location) = 0xFF; // B
            *(imageBuffer + location +1) = 0x00; // G
            *(imageBuffer + location +2) = 0x00; // R
            *(imageBuffer + location +3) = 0; // A
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


void ProgressBar::mouseMoveEvent(int x, int y) {

};

void ProgressBar::freeMemory() {

};