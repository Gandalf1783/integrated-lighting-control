#include "Line.hpp"

Line::Line() {
    this->x1 = 150;
    this->x2 = 100;
    this->y1 = 300;
    this->y2 = 100;
    int dY = y2-y1;
    int dX = x2-x1;
    m = dY/dX;
};

void Line::setFrom(int x, int y) {
    this->x1 = x;
    this->y1 = y;
    m = (y2-y1) / (x2-x1);
};

void Line::setTo(int x, int y) {
    this->x2 = x;
    this->y2 = y;
    m = (y2-y1) / (x2-x1);
};

void Line::render(Framebuffer fb) {
    int x,y;
    this->y2++;
    if((y2-y1) >= 0) {
        for(int y = y1; y < y2-y1; y++) {
            x = y/m;
            fb.setPixel((x1+x), (y1+y), 0xFF, 0xFF, 0xFF);
        }
    } else if((y2-y1) < 0) {
        for(int y = y2; y > 0; y--) {
            x = y/m;
            fb.setPixel((x1+x), (y1+y), 0xFF, 0xFF, 0xFF);
        }
    }
};

void Line::mouseMoveEvent(MouseOnMoveEvent event) {

};

void Line::freeMemory() {

};

void Line::mouseReleasedEvent(MouseOnReleaseEvent event) {

}